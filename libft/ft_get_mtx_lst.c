/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mtx_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 14:34:17 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/08/03 14:34:18 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_mtx_lst	*ft_get_mtx_lst(int mtx_index, t_mtx_lst *mlst)
{
	int		i;

	i = 0;
	while (mlst)
	{
		if (i == mtx_index)
			return (mlst);
		i++;
		mlst = mlst->next;
	}
	return (NULL);
}
