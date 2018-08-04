/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:06:24 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/08/03 15:06:25 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtx_print(t_mtx_lst *mlst)
{
	int		i;
	int		j;
	int		height;
	int		width;
	char	**matrix;

	height = mlst->height;
	width = mlst->width;
	matrix = mlst->mtx;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			ft_putchar(matrix[i][j]);
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
