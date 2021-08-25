/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:50:16 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/24 22:07:21 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char	*uc_buf1;
	unsigned char	*uc_buf2;
	size_t			i;

	if (!n)
		return (0);
	uc_buf1 = (unsigned char *)buf1;
	uc_buf2 = (unsigned char *)buf2;
	i = 0;
	while (i < n - 1 && uc_buf1[i] == uc_buf2[i])
		i++;
	return (uc_buf1[i] - uc_buf2[i]);
}
