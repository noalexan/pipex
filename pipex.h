/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 02:07:56 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/23 04:27:17 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>

# include "libft/libft.h"

typedef struct s_input
{
	char			**argv;
	int				in;
	int				out;
	struct s_input	*next;
}		t_input;

void	ft_wait_all(t_input *list);
void	ft_clear(t_input *list);
void	ft_close_all(t_input *list);
char	*ft_search_in_path(char *cmd, char **path);
char	**ft_get_argv(char *cmd, char **path);

#endif
