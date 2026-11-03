/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:51:04 by angmarqu          #+#    #+#             */
/*   Updated: 2026/09/28 12:31:20 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	ch;

	i = 0;
	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (ptr[i] == ch)
			return ((char *)&ptr[i]);
		i++;
	}
	return (NULL);
}
