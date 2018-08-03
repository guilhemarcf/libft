/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:20:33 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/11 17:20:34 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t max)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen((char *)src);
	if (dst_size > max)
		return (max + src_size);
	i = 0;
	while (src[i] && i < (max - dst_size - 1))
	{
		dst[dst_size + i] = src[i];
		dst[dst_size + i + 1] = '\0';
		i++;
	}
	return (dst_size + src_size);
}
