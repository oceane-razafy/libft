/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:10:11 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/15 19:10:13 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (s == NULL || f == NULL)
		return (NULL);
	dest = ft_strdup(s);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (dest[i])
	{
		dest[i] = (*f)(i, dest[i]);
		i++;
	}
	return (dest);
}
