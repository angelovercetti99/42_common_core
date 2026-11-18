/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 12:09:33 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/18 12:34:20 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_base(unsigned long n, char *base)
{
	unsigned long len;
	int	count;

	len = 0;
	count = 0;
	while (base[len])
		len++;
	if (n >= len)
		count += ft_print_base(n / len, base);
	count += ft_print_char(base[n % len]);
	return (count);
}
