/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:56:00 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/17 18:36:55 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur_last;

	if (!lst)
		return ;
	cur_last = ft_lstlast(*lst);
	if (!cur_last)
		*lst = new;
	else
		cur_last->next = new;
}
