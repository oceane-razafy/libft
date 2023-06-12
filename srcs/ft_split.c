/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:08:53 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/15 19:59:35 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int			nb_words;
	char const	*start;

	nb_words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		start = s;
		while (*s != c && *s)
			s++;
		if ((s - start) > 0)
			nb_words++;
		if (*s != 0)
			s++;
	}
	return (nb_words);
}

static int	ft_strlen2(char const *str, char c)
{
	char const	*start;

	start = str;
	while (*str != c && *str)
		str++;
	return (str - start);
}

static void	ft_free(char **tab, int filled)
{
	int	j;

	j = 0;
	while (j < filled)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

static char	*ft_strndup(char const *str, int n, char **tab, int filled)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
	{
		ft_free(tab, filled);
		return (NULL);
	}
	i = 0;
	while (str[i] && i < n)
	{
		dest[i] = ((char *)str)[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ft_count_words(s, c) && s[i])
	{
		while (s[i] == c && s[i])
			i++;
		tab[j] = ft_strndup(&s[i], ft_strlen2(&s[i], c), tab, j);
		if (tab[j] == NULL)
			return (NULL);
		i = i + ft_strlen2(&s[i], c);
		if (s[i] != 0)
			i++;
		j++;
	}
	tab[ft_count_words(s, c)] = 0;
	return (tab);
}
