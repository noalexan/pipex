/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:19:56 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/17 10:15:51 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

t_cmd	parse_argv(char **path, char *argv)
{
	t_cmd	cmd;

	cmd.args[0] = ft_split(argv, ' ')[0];
	if ((argv + ft_strlen(cmd.args[0]))[0] == '\0'
		|| (argv + ft_strlen(cmd.args[0]))[0] == ' ')
		cmd.args[1] = NULL;
	else
		cmd.args[1] = argv + ft_strlen(cmd.args[0]);
	cmd.args[2] = NULL;
	cmd.cmd_path = find_path(path, cmd.args[0]);
	return (cmd);
}

void	exec_all_cmds(char **env, char **path, char **argv, int *files)
{
	t_cmd	cmd;

	cmd = parse_argv(path, argv[0]);
	dup2(files[1], 1);
	dup2(files[0], 0);
	execve(cmd.cmd_path, cmd.args, env);
	dup2(files[1], 0);
	cmd = parse_argv(path, argv[1]);
	execve(cmd.cmd_path, cmd.args, env);
}
