/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tishigak <tishigak@student.42toky...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 03:42:18 by tishigak          #+#    #+#             */
/*   Updated: 2021/04/17 19:31:02 by tishigak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr_fd_worker(long long_n, int fd)
{
	if (long_n >= 10)
	{
		ft_putnbr_fd_worker(long_n / 10, fd);
		ft_putchar_fd((long_n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(long_n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;

	long_n = n;
	if (long_n < 0)
	{
		ft_putchar_fd('-', fd);
		long_n *= -1;
	}
	ft_putnbr_fd_worker(long_n, fd);
}
