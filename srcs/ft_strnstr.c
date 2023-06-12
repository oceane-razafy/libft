/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:10:30 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/16 03:54:27 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	little_len = ft_strlen(little);
	while (big[i] && i < len)
	{
		while (big[i] != little[0] && big[i] && i < len)
			i++;
		if (i == len)
			return (NULL);
		if ((ft_strncmp(&big[i], little, little_len) == 0)
			&& ((i + little_len - 1) < len))
			return ((char *)(big + i));
		if (big[i] != 0)
			i++;
	}
	return (NULL);
}
