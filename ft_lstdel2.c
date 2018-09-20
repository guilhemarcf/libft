/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 14:02:08 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/18 14:02:41 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel2(t_list **alst)
{
	t_list **flwr;
	t_list *aux;

	flwr = alst;
	aux = *alst;
	while (*flwr != NULL)
	{
		free((*flwr)->content);
		aux = (*flwr)->next;
		free(*flwr);
		*flwr = aux;
	}
	if (flwr != NULL)
		free(*flwr);
	*alst = NULL;
}
