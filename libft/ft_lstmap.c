/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:38:38 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/19 17:02:57 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*first;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	cur = first;
	lst = lst->next;
	while (lst)
	{
		cur->next = ft_lstnew((*f)(lst->content));
		if (!cur->next)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		cur = cur->next;
		lst = lst->next;
	}
	cur->next = 0;
	return (first);
}
