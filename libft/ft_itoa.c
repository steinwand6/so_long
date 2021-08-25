/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 02:34:45 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/12 19:09:07 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_get_digits(long long_n)
{
	int		digit;

	if (long_n == 0)
		return (1);
	if (long_n < 0)
		long_n *= -1;
	digit = 0;
	while (long_n > 0)
	{
		digit++;
		long_n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	long_n;
	int		i;
	int		neg_flg;

	long_n = n;
	neg_flg = long_n < 0;
	i = neg_flg;
	if (neg_flg)
		long_n *= -1;
	i += ft_get_digits(long_n);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	while (long_n >= 10)
	{
		str[i--] = (long_n % 10) + '0';
		long_n /= 10;
	}
	str[i] = long_n + '0';
	if (neg_flg)
		str[--i] = '-';
	return (str);
}
