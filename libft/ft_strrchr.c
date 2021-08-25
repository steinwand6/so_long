/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:57:40 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/16 03:49:59 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		target;
	const char	*last;

	target = (char)c;
	if (!target)
		return ((char *)s + ft_strlen(s));
	last = NULL;
	while (*s)
	{
		if (*s == target)
			last = s;
		s++;
	}
	return ((char *)last);
}
