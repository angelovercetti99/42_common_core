/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:28:42 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/24 14:14:47 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest_str, const void *src_str, size_t n)
{
    size_t i;
    unsigned char *dest;
    unsigned char *src;

    i = 0;
    dest = (unsigned char*) dest_str;
    src = (unsigned char*) src_str;
    if(n == 0)
        return(dest_str);
    if(dest > src)
    {
        i = n;
        while (i > 0)
        {
            i--;
                dest[i] = src[i];
        }
    }
    else
    {
        while(i < n)
        {
            dest[i] = src[i];
                i++;
        }
    }
    return(dest_str);
}