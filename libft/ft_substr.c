/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:14:33 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/05 16:40:21 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t lenght;
	char	*p;

	lenght = ft_strlen(s);
	p = malloc (lenght + 1);
	if (p == NULL)
		return (NULL);
	if (start >= lenght)
			ft_strlcpy(p, s, start);
				return (ft_strlcpy);
	return(p);
}

