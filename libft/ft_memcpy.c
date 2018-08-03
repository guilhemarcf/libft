/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 15:42:51 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/10 15:43:03 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void *odst;

	odst = dst;
	while (n > 0)
	{
		((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (odst);
}
