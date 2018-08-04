/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:16:49 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/12 20:16:51 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*n;
	int		i;

	if (s == NULL)
		return (NULL);
	n = (char *)malloc(sizeof(*s) * (ft_strlen((char *)s) + 1));
	if (n == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		n[i] = f(s[i]);
		i++;
	}
	n[i] = '\0';
	return (n);
}
