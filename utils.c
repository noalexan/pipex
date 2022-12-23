/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 04:15:22 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/23 04:27:27 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_wait_all(t_input *list)
{
	if (list)
	{
		wait(NULL);
		ft_close_all(list->next);
	}
}

void	ft_clear(t_input *list)
{
	int	i;

	if (list)
	{
		ft_clear(list->next);
		i = -1;
		while (list->argv[++i])
			free(list->argv[i]);
		free(list->argv);
		free(list);
	}
}

void	ft_close_all(t_input *list)
{
	if (list)
	{
		close(list->in);
		close(list->out);
		ft_close_all(list->next);
	}
}

char	*ft_search_in_path(char *cmd, char **path)
{
	char	*cmd_path;

	cmd_path = NULL;
	if (*path)
	{
		cmd_path = ft_strjoin(*path, cmd);
		if (!access(cmd_path, X_OK))
		{
			free(cmd);
			return (cmd_path);
		}
		free(cmd_path);
		return (ft_search_in_path(cmd, path + 1));
	}
	free(cmd);
	return (cmd_path);
}

char	**ft_get_argv(char *cmd, char **path)
{
	char	**argv;

	argv = ft_split(cmd, ' ');
	argv[0] = ft_search_in_path(argv[0], path);
	return (argv);
}
