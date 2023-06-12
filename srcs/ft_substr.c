/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:10:52 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/18 17:07:51 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_compute_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;

	if (start > (unsigned int)ft_strlen(s))
	{
		size = 0;
	}
	else
	{
		i = 0;
		while (i < len && s[start++])
		{
			i++;
		}
		size = i;
	}
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = ft_compute_size(s, start, len);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dest[i] = s[start++];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
