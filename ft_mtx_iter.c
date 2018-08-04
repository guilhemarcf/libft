/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtx_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 15:04:06 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/08/03 15:04:07 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtx_iter(t_mtx_lst *mlst, void (*f)(t_mtx_lst *elem))
{
	t_mtx_lst *flwr;

	flwr = mlst;
	while (flwr != NULL)
	{
		f(flwr);
		flwr = flwr->next;
	}
}
