/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:11:21 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/06 19:06:36 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t len;
	char	*p;
	

	len = ft_strlen(n);
	p = malloc(len + 1);
	if (!p)
		return(NULL);
	while (n >= 0)
	{
		len++;
	}
}
