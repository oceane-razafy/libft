/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:09:00 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/15 20:25:53 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if ((char)c == str[i])
			return (&str[i]);
		i++;
	}
	if ((char)c == str[i])
		return (&str[i]);
	return (NULL);
}
