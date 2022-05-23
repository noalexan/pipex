/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:19:56 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/23 12:29:40 by noalexan         ###   ########.fr       */
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
	ft_printf("cmd : { %s, { ", cmd.cmd_path);
	i = -1;
	while (cmd.args[++i])
		ft_printf("%s, ", cmd.args[i]);
	ft_printf("NULL } }\n", cmd.args[0], cmd.args[1], cmd.args[2]);
	return (cmd);
}

void	exec_all_cmds(char **env, char **path, char **argv, int *files)
{
	t_cmd	cmd;
	int		pid;
	int		i;
	int		pipe_fd[2];

	pipe(pipe_fd);
	dup2(pipe_fd[1], 1);
	dup2(files[0], 1);
	i = -1;
	cmd = parse_argv(path, argv[i]);
	pid = fork();
	if (pid == -1)
		err(ERR_FORK);
	else if (pid > 0)
		execve(cmd.cmd_path, cmd.args, env);
	dup2(pipe_fd[0], 0);
	while (argv[++i + 1])
	{
		cmd = parse_argv(path, argv[i]);
		pid = fork();
		if (pid == -1)
			err(ERR_FORK);
		else if (pid > 0)
			execve(cmd.cmd_path, cmd.args, env);
	}
}
