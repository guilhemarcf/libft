/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 19:58:15 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/11 19:58:16 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*ptr;
	unsigned long	cnt;
	unsigned char	cmp;

	cnt = 0;
	ptr = (char *)s;
	while (cnt < n)
	{
		cmp = ptr[cnt];
		if (cmp == (unsigned char)c)
			return (ptr + cnt);
		cnt++;
	}
	return (NULL);
}
