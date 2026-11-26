/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:30:00 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/26 14:26:22 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	ssize_t	n;

	buf = malloc(BUFFER_SIZE + 1);
	n = 1;
	if (!buf)
		n = -1;
	while (ft_strchr(stash, '\n') == NULL && n > 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buf[n] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		stash = tmp;
		if (!stash)
			n = -1;
	}
	free(buf);
	if (n != -1)
		return (stash);
	free(stash);
	return (NULL);
}

char	*extract_line(char *stash)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		i++;
	}
	if (stash[i] == '\n')
		len = i + 1;
	else
		len = i;
	return (ft_substr(stash, 0, len));
}

char	*clean_stash(char *stash)
{
	char	*rest;
	int		i;

	i = 0;
	if (!ft_strchr(stash, '\n'))
	{
		free(stash);
		return (NULL);
	}
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		i++;
	}
	rest = ft_substr(stash, i + 1, ft_strlen(stash) - (i + 1));
	free(stash);
	if (!rest || rest[0] == '\0')
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
