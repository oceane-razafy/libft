/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:41 by orazafy           #+#    #+#             */
/*   Updated: 2022/11/23 15:11:59 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long long int	sizemax;
	void					*dest;

	if ((size == 0) || (nmemb == 0))
	{
		dest = (void *)malloc(sizeof(char));
		((char *)dest)[0] = 0;
		return (dest);
	}
	sizemax = (unsigned long long int)SIZE_MAX;
	if (size > sizemax / nmemb)
		return (NULL);
	dest = (void *)malloc(nmemb * size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}
