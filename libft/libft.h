/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketmoss <ketmoss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 15:19:05 by ketmoss           #+#    #+#             */
/*   Updated: 2026/09/24 13:27:15 by ketmoss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

size_t  ft_strlen(const char *s);
int   ft_atoi(const char *nptr);
int ft_isalnum(int c);
int ft_isdigit(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isprint(int c);
void    *ft_memset(void *s, int c, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_toupper(int c);
int ft_tolower(int c);
char    *ft_strrchr(const char *str, int c);
char    *ft_strchr(const char *str, int c);
void    ft_bzero(void *s, size_t n);
void    *ft_calloc(size_t nmemb, size_t size);
void    *ft_memcpy(void *dest_str, const void * src_str, size_t n);

#endif