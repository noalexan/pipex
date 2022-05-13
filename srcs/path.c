/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:16:10 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/12 13:22:31 by noalexan         ###   ########.fr       */
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
	err(ERR_NO_CMD, cmd);
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

char	**set_path(char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (set_slash(ft_split(env[i] + 5, ':')));
	err(ERR_NO_PATH);
	return (0);
}
