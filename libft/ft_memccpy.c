/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:15:33 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/12 19:06:47 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s_str;
	unsigned char	*d_str;
	size_t			i;

	s_str = (unsigned char *)src;
	d_str = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d_str[i] = s_str[i];
		if ((unsigned char)c == d_str[i])
		{
			return ((void *)(dest + i + 1));
		}
		i++;
	}
	return (NULL);
}
