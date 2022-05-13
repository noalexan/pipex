/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:16:41 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/26 20:51:59 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*strmapi;
	unsigned int	i;

	if (!s)
		return (NULL);
	strmapi = ft_strdup(s);
	if (!strmapi)
		return (0);
	i = -1;
	while (strmapi[++i])
		strmapi[i] = f(i, strmapi[i]);
	return (strmapi);
}
