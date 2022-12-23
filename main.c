/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:59:53 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/23 04:27:33 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_input	*ft_create_list(char **argv, char **path, int s)
{
	t_input	*new;
	int		p[2];

	new = NULL;
	if (*argv)
	{
		new = ft_calloc(1, sizeof(t_input));
		new->argv = ft_get_argv(*(argv), path);
		new->in = s;
		if (!*(argv + 2))
			new->out = open(*(argv + 1), O_CREAT | O_WRONLY | O_TRUNC, 0600);
		else
		{
			pipe(p);
			new->out = p[1];
			new->next = ft_create_list(argv + 1, path, p[0]);
		}
	}
	return (new);
}

char	**ft_get_path(char **env)
{
	char	**path;
	int		i;
	int		j;

	path = NULL;
	if (env && *env)
	{
		if (!ft_strncmp(*env, "PATH", 4))
		{
			path = ft_split(*env + 5, ':');
			i = -1;
			while (path[++i])
			{
				j = -1;
				while (path[i][++j])
					;
				if (path[i][j - 1] != '/')
					path[i][j] = '/';
			}
		}
		else
			return (ft_get_path(env + 1));
	}
	return (path);
}

void	ft_verify(t_input *list)
{
	if (list)
	{
		if (!*(list->argv))
		{
			ft_putendl_fd("command not found", 2);
			exit(4);
		}
		if (list->in < 0 || list->out < 0)
		{
			ft_putendl_fd("error while open", 2);
			exit(5);
		}
		ft_verify(list->next);
	}
}

void	ft_execute(t_input *all, t_input *list, char **env)
{
	int	pid;

	if (list)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(list->in, 0);
			dup2(list->out, 1);
			ft_close_all(all);
			execve(*(list->argv), list->argv, env);
		}
		ft_execute(all, list->next, env);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_input	*list;
	char	**path;

	if (!env || !env[0])
	{
		ft_putendl_fd("environnement not set", 2);
		return (1);
	}
	if (argc < 5)
	{
		ft_putendl_fd("usage: ./pipex <file> <cmd> ... <cmd> <file>", 2);
		return (2);
	}
	path = ft_get_path(env);
	if (!path)
	{
		ft_putendl_fd("PATH unreachable", 2);
		return (3);
	}
	list = ft_create_list(argv + 2, path, open(argv[1], 0400));
	ft_verify(list);
	ft_execute(list, list, env);
	ft_close_all(list);
	ft_wait_all(list);
	return (0);
}
