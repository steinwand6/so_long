/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:15:42 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/12 19:05:36 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	size_t	i;

	if (buf1 == buf2)
		return (buf1);
	i = 0;
	while (i < n)
	{
		((unsigned char *)buf1)[i] = ((unsigned char *)buf2)[i];
		i++;
	}
	return (buf1);
}
