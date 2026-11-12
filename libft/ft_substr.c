/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:14:33 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/06 12:13:51 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	size_t	sub_len;
	char	*p;

	if (s == NULL)
		return (NULL);
	length = ft_strlen(s);
	if (start >= length)
		sub_len = 0;
	else
		sub_len = length - start;
	if (len < sub_len)
		sub_len = len;
	p = malloc(sub_len + 1);
	if (p == NULL)
		return (NULL);
	if (sub_len == 0)
		p[0] = '\0';
	else
		ft_strlcpy(p, s + start, sub_len + 1);
	return (p);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_substr("hello world", 6, 5);
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
