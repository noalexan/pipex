/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:05:48 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/26 20:52:43 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ecriture2(char *result, const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2)
	{
		if (s1)
			j = ft_strlen(result);
		while (i < ft_strlen(s2))
		{
			((char *) result)[j] = ((char *) s2)[i];
			i++;
			j++;
		}
	}
	result[j] = '\0';
	return (result);
}

static char	*ecriture(char *result, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1)
	{
		while (i < ft_strlen(s1))
		{
			((char *) result)[i] = ((char *) s1)[i];
			i++;
		}
	}
	return (ecriture2(result, s1, s2));
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;

	if (!s1)
		result = ft_calloc(ft_strlen(s2) + 1, sizeof(char));
	else if (!s2)
		result = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	else
		result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 2, sizeof(char));
	if (result == NULL)
		return (NULL);
	ecriture(result, s1, s2);
	return (result);
}
