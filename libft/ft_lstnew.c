/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 13:05:18 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/15 13:05:19 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*r;

	r = (t_list *)malloc(sizeof(*r));
	if (r == NULL)
		return (NULL);
	if (content == NULL)
	{
		r->content = NULL;
		r->content_size = 0;
	}
	else
	{
		r->content = malloc(sizeof(void) * content_size);
		if (r->content == NULL)
		{
			free(r);
			return (NULL);
		}
		ft_memcpy(r->content, content, content_size);
		r->content_size = content_size;
	}
	r->next = NULL;
	return (r);
}
