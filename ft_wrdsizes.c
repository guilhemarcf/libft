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
	int		j;
	char	*p;

	if ((w_sizes = (int *)malloc(sizeof(*w_sizes) * q_words)) == NULL)
		return (NULL);
	i = -1;
	while (++i < q_words)
	{
		w_size = 0;
		j = -1;
		p = ft_fndwrds(s, c, (i + 1));
		while ((p[++j] != c) && (p[j] != '\0'))
			w_size++;
		w_sizes[i] = w_size;
	}
	return (w_sizes);
}
