/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:11:21 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/09 11:25:32 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_len(long nbr)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*p;
	long	nbr;

	len = count_len(n);
	p = malloc(len + 1);
	nbr = n;
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		p[0] = '-';
	}
	if (nbr == 0)
		p[0] = '0';
	while (nbr != 0)
	{
		p[len - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
	return (p);
}
