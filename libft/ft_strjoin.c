/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:15:38 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/06 13:09:21 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	p = malloc(ls1 + ls2 + 1);
	if (p == NULL)
		return (NULL);
	p[0] = '\0';
	ft_strlcat (p, s1, ls1 + ls2 + 1);
	ft_strlcat (p, s2, ls1 + ls2 + 1);
	return (p);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s;

	s = ft_strjoin("hello ", "world");
	printf("%s\n", s);
	free(s);
	return (0);
}
*/
