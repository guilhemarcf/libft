/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:24:57 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/12 18:24:59 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	char			*str1;
	char			*str2;
	unsigned char	cmp1;
	unsigned char	cmp2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		cmp1 = (unsigned char)str1[i];
		cmp2 = (unsigned char)str2[i];
		if (cmp1 == cmp2)
			i++;
		else
			return (cmp1 - cmp2);
	}
	return (0);
}
