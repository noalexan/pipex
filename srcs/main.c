/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:22:43 by noalexan          #+#    #+#             */
/*   Updated: 2022/06/08 16:19:49 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_env(char **env, char *find)
{
	int	i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], find, ft_strlen(find)))
			return (env[i] + ft_strlen(find) + 1);
	return (NULL);
}

char	**set_slash(char **path)
{
	int	i;
	int	j;

	i = -1;
	while (path[++i])
	{
		j = -1;
		while (path[i][++j])
			;
		if (path[i][j - 1] != '/')
			path[i][j] = '/';
	}
	return (path);
}

int	open_files(char *filename, int inputfile)
{
	int	file;

	if (inputfile)
	{
		file = open(filename, O_RDONLY);
		if (file < 0)
			ft_printf(2, ERR_FILE, filename);
	}
	else
		file = open(filename, O_WRONLY | O_TRUNC | O_CREAT);
	return (file);
}

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
	// while (cmd.args[++i])
	// 	;
	// cmd.args[i] = NULL;
	cmd.cmd_path = find_path(path, cmd.args[0]);
	return (cmd);
}

void	exec_cmd(char **path, char **env, char **argv, int *files)
{
	t_cmd	cmd;

	(void) files;
	cmd = parse_argv(path, argv[2]);
	(void) env;
	execve(cmd.cmd_path, cmd.args, env);
	free(cmd.cmd_path);
	free(*cmd.args);
	free(cmd.args);
}

void	exec_cmds(char **path, char **env, char **argv, int *files)
{
	
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
	system("leaks pipex");
	return (0);
}
