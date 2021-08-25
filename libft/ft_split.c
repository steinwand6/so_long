/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:29:38 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/17 20:56:18 by tishigak         ###   ########.fr       */
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

static	size_t	ft_set_next_word(char const **str_ptr, char c)
{
	size_t		i;
	char const	*str;

	str = *str_ptr;
	while (*str == c)
		str++;
	*str_ptr = str;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static	size_t	ft_count_word(char const *str, char c)
{
	size_t	count;
	int		find_sep;
	int		prev_sep_flg;

	count = 0;
	find_sep = 1;
	prev_sep_flg = 1;
	while (*str)
	{
		find_sep = 0;
		if (*str == c)
			find_sep = 1;
		if (find_sep && !prev_sep_flg)
			count++;
		prev_sep_flg = find_sep;
		str++;
	}
	if (!find_sep)
		count++;
	return (count);
}

static	void	*ft_clean(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	size_t	word_length;
	size_t	i;
	size_t	word_count;
	char	**tab;

	if (!str)
		return (NULL);
	word_count = ft_count_word(str, c);
	tab = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		word_length = ft_set_next_word(&str, c);
		tab[i] = ft_strndup(str, word_length);
		if (!(tab[i]))
			return (ft_clean(tab));
		str = str + word_length;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
