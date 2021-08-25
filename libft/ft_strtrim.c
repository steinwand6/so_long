/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 21:28:17 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/24 22:08:43 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strndup(char const *src, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc(n + 1);
	if (!ptr)
		return (NULL);
	while (src[i] && i < n)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static	int	ft_is_target_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static	size_t	ft_strtrim_tail_idx(char const *s1, char const *set,
				size_t len)
{
	while (&s1[len] != s1)
	{
		if (!ft_is_target_in_set(s1[len - 1], set))
			break ;
		len--;
	}
	return (len);
}

static	size_t	ft_strtrim_head_idx(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!ft_is_target_in_set(s1[i], set))
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s_len;
	size_t	start;
	size_t	result_len;

	if (!s1 || !set)
		return (NULL);
	s_len = ft_strlen(s1);
	s_len = ft_strtrim_tail_idx(s1, set, s_len);
	start = ft_strtrim_head_idx(s1, set);
	if (s_len <= start)
		result_len = 0;
	else
		result_len = s_len - start;
	return (ft_strndup(s1 + start, result_len));
}
