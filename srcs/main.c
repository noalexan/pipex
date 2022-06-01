/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:33:09 by noalexan          #+#    #+#             */
/*   Updated: 2022/05/25 12:36:03 by noahalexand      ###   ########.fr       */
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
	system("leaks pipex");
	return (EXIT_SUCCESS);
}

/*

Here_doc:
	faire une structure qui contient tout.
	faire une fonction qui a pour but de lire les fichiers.

Trouver ce qu'il me reste a faire...

*/
