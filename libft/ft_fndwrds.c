/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fndwrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:22:05 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/16 15:22:22 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fndwrds(char *s, char c, int n)
{
	char	previous;
	int		q_words;

	q_words = 0;
	previous = c;
	while (*s)
	{
		if (*s == c)
		{
			if (previous != c)
				previous = *s;
		}
		else
		{
			if (previous == c)
			{
				q_words++;
				previous = *s;
			}
		}
		if (q_words == n)
			return (s);
		s++;
	}
	return (NULL);
}
