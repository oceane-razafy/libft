/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:21 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/15 19:06:23 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

static int	ft_char_to_int(char *str)
{
	int	nb;
	int	i;

	i = 1;
	nb = str[0] % '0';
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] % '0');
		i++;
	}
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	char	*str;
	char	*str_nb;
	int		sign;

	sign = 1;
	if (*nptr == 0)
		return (0);
	str = (char *)nptr;
	while (ft_isspace(*str) && (*str))
		str++;
	if ((*str < '0' || *str > '9') && (*str != '+') && (*str != '-'))
		return (0);
	str_nb = str;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
		str_nb = str;
		if (*str < '0' || *str > '9')
			return (0);
	}
	return (sign * ft_char_to_int(str_nb));
}
