/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:27:30 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/03 12:11:54 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if (!dest_str && !src_str)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dest_str;
	src = (unsigned char *)src_str;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
