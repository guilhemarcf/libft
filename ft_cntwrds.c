/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwrds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:19:49 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/16 15:20:05 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntwrds(char *s, char c)
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
		s++;
	}
	return (q_words);
}
