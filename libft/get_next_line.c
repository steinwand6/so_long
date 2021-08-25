/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 19:52:18 by tishigak          #+#    #+#             */
/*   Updated: 2021/08/09 00:43:57 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnl_split(char **strage, char **line, char *split_ptr)
{
	char	*tmp;

	if (!split_ptr)
	{
		*line = ft_strdup(*strage);
		if (!*line)
			return (1);
		free(*strage);
		*strage = NULL;
	}
	else
	{
		*split_ptr = '\0';
		*line = ft_strdup(*strage);
		if (!*line)
			return (1);
		tmp = *strage;
		*strage = ft_strdup(split_ptr + 1);
		free(tmp);
		if (!*strage)
			return (1);
	}
	return (0);
}

static char	*ft_gnl_strjoin(char *s1, char *s2, size_t len2)
{
	size_t	len1;
	char	*ptr;
	size_t	i;

	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	ptr = malloc(len1 + len2 + 1);
	if (!ptr)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}

ssize_t	ft_gnl_read_and_store(int fd, char **buf, size_t size, char **strage)
{
	ssize_t		result;

	result = read(fd, *buf, size);
	if (result == -1)
	{
		free(*strage);
		free(*buf);
		return (-1);
	}
	(*buf)[result] = '\0';
	*strage = ft_gnl_strjoin(*strage, *buf, (size_t)result);
	if (!*strage)
	{
		free(*buf);
		*buf = NULL;
		return (-1);
	}
	return (result);
}

int	get_next_line(int fd, char **line)
{
	static char	*strage = NULL;
	char		*buf;
	ssize_t		result;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
	{
		free(strage);
		return (-1);
	}
	result = 1;
	while (result != 0 && (strage == NULL || !ft_strchr(strage, '\n')))
	{
		result = ft_gnl_read_and_store(fd, &buf, BUFFER_SIZE, &strage);
		if (result == -1)
			return (-1);
	}
	free(buf);
	if (!ft_gnl_split(&strage, line, ft_strchr(strage, '\n')))
		return (strage != NULL);
	free(strage);
	return (-1);
}
