/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 14:22:25 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/29 12:51:27 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s)
{
    size_t len;
    char *ptr;

    len = ft_strlen(s);
    ptr = malloc(len + 1);
    if(ptr == NULL)
        return(NULL);
    ft_strlcpy(ptr, s, len + 1);
    return(ptr);
}