/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:22:26 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/09 14:50:56 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}
static void	free_all(char **arr, size_t j)
{
	while (j > 0)
	{
		j--;
		free(arr[j]);
	}
	free(arr);
}
char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	j;
	size_t	start;
	char	**arr;

	words = count_words(s, c);
	i = 0;
	j = 0;
	start = 0;
	arr = malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr[words] = NULL;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		arr[j] = ft_substr(s, start, i - start);
		if (!arr[j])
		{
			free_all(arr, j);
			return (NULL);
		}
		j++;
	}
	return (arr);
}
