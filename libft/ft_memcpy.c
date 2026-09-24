/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 12:27:30 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/24 12:51:12 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest_str, const void * src_str, size_t n)
{
    size_t i;
    unsigned char *dest;
    unsigned char *src;

    i = 0;
    dest = (unsigned char*)dest_str;
    src = (unsigned char*)src_str;
    while( i < n)
    {
        dest[i] = src[i];
            i++;
    }
    return (dest);
}