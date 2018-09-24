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

	if ((w_sizes = ft_wrdsizes(s, q_words, c)) == NULL)
		return (NULL);
	if ((str = (char **)malloc(sizeof(*str) * (q_words + 1))) == NULL)
		return (NULL);
	i = -1;
	while (++i < q_words)
	{
		if ((str[i] = (char *)malloc(sizeof(**str) * (w_sizes[i] + 1))) == NULL)
			return (ft_free_all(str, i));
	}
	str[i] = NULL;
	free(w_sizes);
	return (str);
}
