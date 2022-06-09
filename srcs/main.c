/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:22:43 by noalexan          #+#    #+#             */
/*   Updated: 2022/06/09 10:04:37 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **path, char *cmd)
{
	int		i;
	char	*path_cmd;

	i = -1;
	while (path[++i])
	{
		path_cmd = ft_strjoin(path[i], cmd);
		if (!access(path_cmd, 0))
			return (path_cmd);
		free(path_cmd);
	}
	ft_printf(2, ERR_NO_CMD, cmd);
	return (NULL);
}

t_cmd	parse_argv(char **path, char *argv)
{
	t_cmd	cmd;
	int		i;

	cmd.args = ft_split(argv, ' ');
	i = -1;
	cmd.cmd_path = find_path(path, cmd.args[0]);
	return (cmd);
}

void	exec_cmd(t_cmd cmd, char **env, int *files)
{
	int	pid;
	int	i;

	pid = fork();
	if (!pid)
	{
		dup2(files[0], STDIN);
		dup2(files[1], STDOUT);
		execve(cmd.cmd_path, cmd.args, env);
	}
	wait(NULL);
	free(cmd.cmd_path);
	i = -1;
	while (cmd.args[++i])
		free(cmd.args[i]);
	free(cmd.args);
}

void	exec_cmds(char **path, char **env, char **argv, int *files)
{
	int	pipe_fd[2];

	pipe(pipe_fd);
	exec_cmd(parse_argv(path, argv[2]), env, (int []){files[0], pipe_fd[1]});
	close(pipe_fd[1]);
	exec_cmd(parse_argv(path, argv[3]), env, (int []){pipe_fd[0], files[1]});
	close(pipe_fd[0]);
}

int	main(int argc, char **argv, char **env)
{
	char	*tmp;
	char	**path;
	int		files[2];

	if (argc != 5)
		ft_printf(2, ERR_ARG);
	if (!*env)
		ft_printf(2, ERR_NO_ENV);
	tmp = get_env(env, "PATH");
	if (!tmp)
		ft_printf(2, ERR_NO_PATH);
	path = set_slash(ft_split(tmp, ':'));
	files[0] = open_files(argv[1], 1);
	files[1] = open_files(argv[4], 0);
	exec_cmds(path, env, argv, files);
	close(files[0]);
	close(files[1]);
	return (0);
}
