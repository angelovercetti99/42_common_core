/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:01:54 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/22 14:11:20 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr;
    size_t i;
    
    ptr = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        ptr[i] = c;
            i++;
    }
    return(s);
}
