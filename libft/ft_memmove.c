/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:28:42 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/03 12:11:54 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src_str, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (!dest_str && !src_str)
		return (NULL);
	dest = (unsigned char *)dest_str;
	src = (const unsigned char *)src_str;
	if (dest <= src)
		return (ft_memcpy(dest_str, src_str, n));
	while (n > 0)
	{
		n--;
		dest[n] = src[n];
	}
	return (dest_str);
}
