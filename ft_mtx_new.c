/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:58:46 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/08/03 14:58:48 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_plc_matrix(char **matrix, int height, int width)
{
	char	**mtx_lst;
	int		i;
	int		j;

	mtx_lst = (char **)malloc(sizeof(*mtx_lst) * height);
	if (mtx_lst == NULL)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		mtx_lst[i] = (char *)malloc(sizeof(**mtx_lst) * width);
		if (mtx_lst[i] == NULL)
		{
			ft_free_all(mtx_lst, i);
			return (NULL);
		}
		j = -1;
		while (++j < width)
			mtx_lst[i][j] = matrix[i][j];
	}
	return (mtx_lst);
}

t_mtx_lst	*ft_mtx_new(char **matrix, int height, int width)
{
	t_mtx_lst		*r;

	r = (t_mtx_lst *)malloc(sizeof(*r));
	if (r == NULL)
		return (NULL);
	if (matrix == NULL)
	{
		r->mtx = NULL;
		r->height = 0;
		r->width = 0;
	}
	else
	{
		r->mtx = ft_plc_matrix(matrix, height, width);
		r->height = height;
		r->width = width;
	}
	r->next = NULL;
	return (r);
}
