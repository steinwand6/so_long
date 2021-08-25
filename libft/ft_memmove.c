/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:50:23 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/12 19:05:07 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *buf1, const void *buf2, size_t n)
{
	size_t			i;
	unsigned char	*uc_buf1;
	unsigned char	*uc_buf2;

	uc_buf1 = (unsigned char *)buf1;
	uc_buf2 = (unsigned char *)buf2;
	if (buf1 == buf2)
		return (buf1);
	if (n == 0)
		return (buf1);
	if (buf1 > buf2)
	{
		i = n;
		while (i-- > 0)
			uc_buf1[i] = uc_buf2[i];
	}
	else
		ft_memcpy(buf1, buf2, n);
	return (buf1);
}
