/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:08:39 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/16 01:55:03 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		nb_digits;
	int		digit;
	char	digit_char;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	if (n == 0)
		ft_putstr_fd("0", fd);
	if (n < 0 && n != -2147483648)
	{
		ft_putstr_fd("-", fd);
		n = -n;
	}
	i = 0;
	nb_digits = ft_count_digit(n);
	while (i < nb_digits)
	{
		digit = n / ft_power(10, nb_digits - 1 - i) % 10;
		digit_char = digit + '0';
		ft_putchar_fd(digit_char, fd);
		i++;
	}
}
