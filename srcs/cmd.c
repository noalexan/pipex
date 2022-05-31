/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:19:56 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/31 14:57:42 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_cmd	parse_argv(char **path, char *argv)
{
	t_cmd	cmd;
	int		i;

	cmd.args = ft_split(argv, ' ');
	i = -1;
	while (cmd.args[++i])
		;
	cmd.args[i] = NULL;
	cmd.cmd_path = find_path(path, cmd.args[0]);
	return (cmd);
}

char	*exec_cmd(char **env, t_cmd cmd, char *input)
{
	int	pid;
	int	p[2];

	pipe(p);
	ft_printf(p[1], input);
	pid = fork();
	if (pid == 0)
	{
		dup2(p[1], 1);
		dup2(p[0], 0);
		execve(cmd.cmd_path, cmd.args, env);
	}
	close(p[1]);
	return (read_file(p[0]));
}

void	exec_all_cmds(char **env, char **path, char **argv, int *files)
{
	char	*output;
	int		i;

	(void) env;
	(void) path;
	(void) argv;
	(void) files;

	i = 0;
	output = exec_cmd(env, parse_argv(path, argv[i]), read_file(files[0]));
	while (argv[++i])
	{
		output = exec_cmd(env, parse_argv(path, argv[i]), output);
		free(output);
	}
	ft_printf(1, output);
}
