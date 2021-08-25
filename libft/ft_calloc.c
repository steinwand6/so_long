/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 00:49:20 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/17 00:43:50 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	need;

	need = count * size;
	if (count == 0 || size == 0)
		need = 1;
	else if (count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(need);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, need);
	return (ptr);
}
