/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:10:44 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/15 21:32:38 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_srch(char const c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_check(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_srch(s1[i], set) == 1 && s1[i])
		i++;
	return (i);
}

static size_t	ft_check2(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (ft_srch(s1[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*dest;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_check(s1, set);
	if (s1[start] == 0)
	{
		dest = (char *)malloc(sizeof(char));
		if (dest == NULL)
			return (NULL);
		*dest = 0;
		return (dest);
	}
	end = ft_check2(s1, set);
	dest = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		dest[i++] = s1[start++];
	dest[i] = 0;
	return (dest);
}
