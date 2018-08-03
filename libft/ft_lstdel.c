/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 14:43:21 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/15 14:43:22 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list **flwr;
	t_list *aux;

	flwr = alst;
	aux = *alst;
	while (*flwr != NULL)
	{
		del((*flwr)->content, (*flwr)->content_size);
		aux = (*flwr)->next;
		free(*flwr);
		*flwr = aux;
	}
	if (flwr != NULL)
		free(*flwr);
	*alst = NULL;
}
