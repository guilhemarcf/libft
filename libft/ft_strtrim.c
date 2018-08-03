/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:13:15 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/13 10:13:16 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_front(char *p)
{
	while ((*p == ' ' || *p == '\n' || *p == '\t') && (*p != '\0'))
		p++;
	return (p);
}

static char	*trim_back(char *p, int size)
{
	while ((*p == ' ' || *p == '\n' || *p == '\t') && (size >= 0))
	{
		size--;
		p--;
	}
	return (p);
}

char		*ft_strtrim(char const *s)
{
	char	*p1;
	char	*p2;
	char	*r;
	long	trim_size;

	if (s == NULL)
		return (NULL);
	p1 = (char *)s;
	p2 = p1 + ft_strlen(p1) - 1;
	p1 = trim_front(p1);
	if (*p1 == '\0')
		p2 = p1;
	else
		p2 = trim_back(p2, ft_strlen(p1) - 1);
	trim_size = p2 - p1 + 1;
	r = (char *)malloc(sizeof(*r) * (trim_size + 1));
	if (r == NULL)
		return (NULL);
	r[trim_size] = '\0';
	while (--trim_size >= 0)
		r[trim_size] = p1[trim_size];
	return (r);
}
