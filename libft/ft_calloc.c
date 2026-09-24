/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:09:51 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/24 12:09:52 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void    *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    ptr = malloc(nmemb * size);
    if(ptr == NULL)
        return(0);
    ft_bzero(ptr, nmemb * size);
    return (ptr);
}
/*#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    void *ptr = ft_calloc(0, 5);
    printf("%p", ptr);

    free (ptr);
    return(0);
}*/