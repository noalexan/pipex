/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:33:09 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/23 09:52:13 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	char	**path;
	int		*files;

	if (argc < 5)
		err(ERR_ARG);
	path = set_path(env);
	files = open_files(argv);
	exec_all_cmds(env, path, argv + 2, files);
	close(files[0]);
	close(files[1]);
	// system("leaks pipex");
	return (EXIT_SUCCESS);
}
