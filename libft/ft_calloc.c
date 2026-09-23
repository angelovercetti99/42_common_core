/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:09:51 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/23 13:54:53 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void    *ft_calloc(size_t nmemb, size_t size)
{
    char *ptr;
    size_t i;

    ptr = malloc(nmemb * size);
    i = 0;
    if(ptr == 0)
        return(0);
    while(i < (nmemb * size))
    {
        ptr[i] = 0;
            i++;
    }
    return (ptr);
}