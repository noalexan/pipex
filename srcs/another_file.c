/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:04:38 by noalexan          #+#    #+#             */
/*   Updated: 2022/06/09 10:18:06 by noalexan         ###   ########.fr       */
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
		file = open(filename, O_RDONLY);
	else
		file = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (file < 0)
		ft_printf(2, ERR_FILE, filename);
	return (file);
}
