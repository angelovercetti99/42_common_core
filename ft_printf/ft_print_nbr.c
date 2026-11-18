/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 11:41:20 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/18 12:08:41 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_nbr(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		count += ft_print_nbr(nb / 10);
	count += ft_print_char(nb % 10 + '0');
	return (count);
}
