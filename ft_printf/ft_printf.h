/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:30:00 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/18 13:30:00 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_conversion(char c, va_list *args);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_base(unsigned long n, char *base);
int	ft_print_ptr(void *ptr);

#endif
