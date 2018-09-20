/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bldstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:24:40 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/16 15:25:10 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_bldstr(char *s, int q_words, char c)
{
	char	**str;
	int		i;
	int		*w_sizes;

	i = -1;
	w_sizes = ft_wrdsizes(s, q_words, c);
	if (w_sizes == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (q_words + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (++i < q_words)
	{
		str[i] = (char *)malloc(sizeof(char) * (w_sizes[i] + 1));
		if (str[i] == NULL)
			return (ft_free_all(str, i));
	}
	str[i] = NULL;
	return (str);
}
