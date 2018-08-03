/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 12:39:47 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/13 12:39:49 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		q_words;
	int		i;
	int		j;
	char	**str;
	char	*p1;

	if (s == NULL)
		return (NULL);
	q_words = ft_cntwrds((char *)s, c);
	str = ft_bldstr((char *)s, q_words, c);
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < q_words && str[i] != NULL)
	{
		j = 0;
		p1 = ft_fndwrds((char *)s, c, (i + 1));
		while (p1[j] != c && p1[j] != '\0')
		{
			str[i][j] = p1[j];
			j++;
		}
		str[i][j] = '\0';
	}
	return (str);
}
