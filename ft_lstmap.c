/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:22:23 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/15 15:22:24 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n;
	t_list	*r;

	r = NULL;
	if (lst != NULL)
	{
		n = f(lst);
		r = n;
		while (lst->next != NULL)
		{
			n->next = f(lst->next);
			lst = lst->next;
			n = n->next;
		}
	}
	return (r);
}
