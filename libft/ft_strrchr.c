/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:23:50 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/11 18:23:53 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		s_size;

	s_size = ft_strlen((char *)s);
	ptr = (char *)s;
	if (ptr[s_size] == (unsigned char)c)
		return (ptr + s_size);
	while (--s_size >= 0)
	{
		if (ptr[s_size] == (unsigned char)c)
			return (ptr + s_size);
	}
	return (NULL);
}
