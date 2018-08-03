/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:59:55 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/13 09:59:57 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n / 10)
			ft_putnbr_fd(-(n / 10), fd);
		n = -(n % 10) + '0';
		ft_putchar_fd(n, fd);
	}
	else
	{
		if (n / 10)
			ft_putnbr_fd(n / 10, fd);
		n = n % 10 + '0';
		ft_putchar_fd(n, fd);
	}
}
