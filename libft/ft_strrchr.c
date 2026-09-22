/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:10:50 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/22 12:45:00 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int i;

    i = ft_strlen(str) - 1;
    if(c == '\0')
        return((char *)&str[i+1]);
    while(i >= 0)
    {
        if(str[i] == (char)c)
            return ((char *)&str[i]);
        i--;
    }
    return NULL;
}