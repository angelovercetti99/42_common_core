/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 13:10:54 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/28 14:16:12 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t i;

    i = 0;
    if(dstsize == 0)
        return(ft_strlen(src));
    while(src[i] && i < dstsize - 1)
    {
        dst[i] = src[i];
            i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}