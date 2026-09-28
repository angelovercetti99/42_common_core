/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:51:04 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/28 12:12:57 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char ptr;

    i = 0;
    ptr = (unsigned char *)s;
    while(i < n)
        i++;
    if(s[i] == c)
        return(s);
    else
        return(0);
}