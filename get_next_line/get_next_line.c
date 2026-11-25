/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:30:00 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/25 14:15:20 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	n;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	n = 1;
	while (ft_strchr(stash, '\n') == NULL && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[n] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = tmp;
	}
	free(buf);
	return (stash);
}
