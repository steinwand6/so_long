/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:55:53 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/16 17:51:24 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	length;
	char	*ptr;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	if (length <= start)
		length = 0;
	else
	{
		length = length - start;
		if (length > len)
			length = len;
	}
	ptr = malloc(length + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, length);
	*(ptr + length) = '\0';
	return (ptr);
}
