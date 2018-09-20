/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 00:11:42 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/09/14 00:11:51 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew2(char *content)
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
		r->content = ft_strdup(content);
		if (r->content == NULL)
		{
			free(r);
			return (NULL);
		}
		r->content_size = ft_strlen(content) + 1;
	}
	r->next = NULL;
	return (r);
}

