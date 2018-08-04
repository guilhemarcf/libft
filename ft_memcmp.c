/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 20:37:54 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/11 20:37:55 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	char			*p1;
	char			*p2;
	unsigned char	cmp1;
	unsigned char	cmp2;

	i = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	while (i < n)
	{
		cmp1 = (unsigned char)p1[i];
		cmp2 = (unsigned char)p2[i];
		if (cmp1 == cmp2)
			i++;
		else
			return (cmp1 - cmp2);
	}
	return (0);
}
