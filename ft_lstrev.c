/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:48:39 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/16 15:48:42 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*rec_elem(t_list *p1, t_list *p2)
{
	t_list	*new_begin;

	if (p2->next == NULL)
	{
		p2->next = p1;
		return (p2);
	}
	else
	{
		new_begin = rec_elem(p2, p2->next);
		p2->next = p1;
		return (new_begin);
	}
}

t_list			*ft_lstrev(t_list **lst)
{
	t_list *new_begin;

	if (*lst != NULL)
	{
		if ((*lst)->next != NULL)
		{
			new_begin = rec_elem(*lst, (*lst)->next);
			(*lst)->next = NULL;
			return (new_begin);
		}
		else
			return (*lst);
	}
	else
		return (NULL);
}
