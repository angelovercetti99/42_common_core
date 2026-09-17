/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 12:11:58 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/17 13:51:38 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while((s1[i] && s2[i]) && (s1[i] == s2[i]) && (i < n))
    {
        i++;
    }
    if (i < n)
    {
        return(s1[i] - s2[i]);
    }
    return(0);
}

/* int main (void)
{
    char *a = "Hello02";
    char *b = "Hello1200";
    size_t n = 6;
    
    printf("%d", ft_strncmp(a, b, n));
}*/