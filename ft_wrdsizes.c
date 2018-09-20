/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:25:57 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/16 15:26:11 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_wrdsizes(char *s, int q_words, char c)
{
	int		w_size;
	int		*w_sizes;
	int		i;
	char	*p;

	w_sizes = (int *)malloc(sizeof(int) * q_words);
	if (w_sizes == NULL)
		return (NULL);
	i = -1;
	while (++i < q_words)
	{
		w_size = 0;
		p = ft_fndwrds(s, c, (i + 1));
		while (*p != c && *p != '\0')
		{
			w_size++;
			p++;
		}
		w_sizes[i] = w_size;
	}
	free(w_sizes);
	return (w_sizes);
}
