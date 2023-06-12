/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:09:28 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/16 04:19:46 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncat(char *dst, const char *src, size_t n, size_t len)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[len++] = src[i];
		i++;
	}
	dst[len] = 0;
	return (dst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	if (size > len + 1)
		ft_strncat(dst, src, size - len - 1, len);
	if (size < len)
		return (size + ft_strlen(src));
	else
		return (len + ft_strlen(src));
}
