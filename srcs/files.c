/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:27:07 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/16 15:28:26 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	*open_files(char **argv)
{
	int	*files;
	int	i;

	files = (int *) ft_calloc(2, sizeof(int));
	files[0] = open(argv[1], O_RDONLY);
	i = -1;
	while (argv[++i])
		;
	files[1] = open(argv[i - 1], O_WRONLY);
	if (!ft_strcmp(argv[1], argv[i - 1]))
		err(ERR_SAME_FILE);
	if (files[0] < 1)
		err(ERR_FILE, argv[1]);
	if (files[1] < 1)
		err(ERR_FILE, argv[i - 1]);
	return (files);
}

char	*read_file(int fd)
{
	char	*content;
	char	*buffer;

	content = get_next_line(fd);
	buffer = get_next_line(fd);
	while (buffer)
	{
		content = ft_strjoin(content, buffer);
		buffer = get_next_line(fd);
	}
	return (content);
}
