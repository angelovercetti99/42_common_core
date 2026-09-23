/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:05:00 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/23 12:17:23 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if(str[i] == (char)c)
            return ((char *)&str[i]);    
        i++;
    }
    if(str[i] == (char)c)
        return ((char *)&str[i]);
    return NULL;
}