/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:17:15 by noalexan          #+#    #+#             */
/*   Updated: 2022/06/09 10:05:33 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* =============== INCLUDES ================= */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "structs.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

/* ================ DEFINE ================== */

# define ERR_ARG		"Usage: ./pipex <file1> <cmd1> <cmd2> <file2>"
# define ERR_NO_ENV		"Environement not set"
# define ERR_NO_PATH	"Pipex can't access to PATH environement variable"
# define ERR_FILE		"Unable to open file %s"
# define ERR_SAME_FILE	"The two files are same"
# define ERR_NO_CMD		"Command %s not found"
# define ERR_FORK		"Unable to fork"
# define ERR_PIPE		"Unable to pipe"

# define STDERR	2
# define STDOUT	1
# define STDIN	0

/* ================ OTHER =================== */

char	*get_env(char **env, char *find);
char	**set_slash(char **path);
int		open_files(char *filename, int inputfile);

/* ========================================== */

#endif
