/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:41:30 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/12 19:06:23 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	target;
	unsigned char	*uc_buf;
	size_t			i;

	target = (unsigned char)ch;
	uc_buf = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		if (target == uc_buf[i])
			return ((void *)buf + i);
		i++;
	}
	return (NULL);
}
