/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:52:23 by noalexan          #+#    #+#             */
/*   Updated: 2022/12/23 04:28:20 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	char	*a;
	char	*b;
	size_t	i;

	i = 0;
	a = (char *)destination;
	b = (char *)source;
	while (i < size)
	{
		a[i] = b[i];
		i++;
	}
	return (destination);
}
