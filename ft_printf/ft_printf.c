/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:06:46 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/20 12:12:47 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char c, va_list *args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(*args, int)));
	if (c == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_print_nbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_print_base(va_arg(*args, unsigned int), "0123456789"));
	if (c == 'x')
		return (ft_print_base(va_arg(*args, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_print_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_print_ptr(va_arg(*args, void *)));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				break ;
			count += ft_conversion(format[i + 1], &args);
			i += 2;
		}
		else
			count += ft_print_char(format[i++]);
	}
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;

	a = printf("%c %s %d %u %x %p %%\n", 'a', "ola", -42, 42, 255, &a);
	b = ft_printf("%c %s %d %u %x %p %%\n", 'a', "ola", -42, 42, 255, &a);
	printf("%d %d\n", a, b);
	return (0);
}
*/

/*
#include <stdio.h>

int	main(void)
{
	ft_printf("Hello %a 42\n");
	return (0);
}*/
