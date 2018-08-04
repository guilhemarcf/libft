/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:12:12 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/12 19:12:13 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*p;

	p = malloc(size + 1);
	if (p == NULL)
		return (NULL);
	while ((long long)size >= 0)
	{
		((char *)p)[size] = '\0';
		size--;
	}
	return (p);
}
