/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:26:33 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/13 15:04:00 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*exec_cmd(char **env, char **path, char **cmd, int *files)
{
	char	*cmd_path;
	int		pid;

	cmd_path = find_path(path, cmd[0]);
	pid = fork();
	if (pid < 0)
		err(ERR_FORK);
	else if (pid == 0)
	{
		dup2(files[1], 1);
		dup2(files[0], 0);
		execve(cmd_path, cmd, env);
	}
	free(cmd);
	close(files[1]);
	return (read_file(files[0]));
}

char	**parse_cmd(char *argv)
{
	char	**cmd;

	cmd = ft_calloc(4, sizeof(char *));
	cmd[0] = argv;
	cmd[1] = "-n";
	cmd[2] = NULL;
	cmd[3] = NULL;
	return (cmd);
}

void	exec_all_cmds(char **env, char **path, char **argv, int *files)
{
	int		i;
	char	*input;
	int		pipe_files[2];

	if (pipe(pipe_files) == -1)
		err(ERR_PIPE);
	i = -1;
	input = read_file(files[0]);
	while (argv[++i + 1])
	{
		write(pipe_files[1], input, ft_strlen(input));
		input = exec_cmd(env, path, parse_cmd(argv[i]), pipe_files);
		write(files[1], input, ft_strlen(input));
	}
	close(pipe_files[0]);
	close(pipe_files[1]);
	free(input);
}
