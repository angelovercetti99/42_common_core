/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angmarqu <angmarqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:56:39 by angmarqu          #+#    #+#             */
/*   Updated: 2026/11/12 21:23:27 by angmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nova;
	t_list	*no;
	void	*conteudo;

	if (!f || !del)
		return (NULL);
	nova = NULL;
	while (lst != NULL)
	{
		conteudo = f(lst->content);
		no = ft_lstnew(conteudo);
		if (!no)
		{
			del(conteudo);
			ft_lstclear(&nova, del);
			return (NULL);
		}
		ft_lstadd_back(&nova, no);
		lst = lst->next;
	}
	return (nova);
}

/*
#include <stdio.h>

void	*copy(void *c)
{
	return (ft_strdup(c));
}

void	nothing(void *c)
{
	(void)c;
}

int	main(void)
{
	t_list	*l;
	t_list	*m;
	t_list	*p;

	l = ft_lstnew("a");
	ft_lstadd_back(&l, ft_lstnew("b"));
	m = ft_lstmap(l, copy, free);
	p = m;
	while (p)
	{
		printf("%s\n", (char *)p->content);
		p = p->next;
	}
	ft_lstclear(&m, free);
	ft_lstclear(&l, nothing);
	return (0);
}
*/
