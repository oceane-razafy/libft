/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:07:30 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/15 21:18:22 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_case(int nb)
{
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	else
		return (ft_strdup("0"));
}

static int	ft_power(int nb, int power)
{
	int	res;

	res = 1;
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

static int	ft_count_digit(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		nb = -nb;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static char	*ft_malloc(int *nb, int nb_digits, int *stop)
{
	char	*str;

	if (*nb >= 0)
	{
		str = (char *)malloc(sizeof(char) * (nb_digits + 1));
		if (str == NULL)
			return (NULL);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (nb_digits + 2));
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		(*stop)++;
		*nb = -(*nb);
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		nb_digits;
	int		stop;
	int		digit;

	if (n == -2147483648 || n == 0)
		return (ft_case(n));
	nb_digits = ft_count_digit(n);
	stop = nb_digits;
	i = 0;
	if (n < 0)
		i = 1;
	str = ft_malloc(&n, nb_digits, &stop);
	if (str == NULL)
		return (NULL);
	while (i < stop)
	{
		digit = n / ft_power(10, nb_digits - 1) % 10;
		str[i++] = digit + '0';
		nb_digits--;
	}
	str[stop] = 0;
	return (str);
}
