/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:34:15 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/12 20:34:16 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*p1;
	char	*p2;
	char	*r;
	int		i;
	int		j;

	p1 = (char *)s1;
	p2 = (char *)s2;
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup((char *)s2));
	if (s2 == NULL && s1 != NULL)
		return (ft_strdup((char *)s1));
	if (s2 == NULL && s1 == NULL)
		return (NULL);
	r = (char *)malloc(sizeof(*r) * (ft_strlen(p1) + ft_strlen(p2) + 1));
	if (r == NULL)
		return (NULL);
	i = -1;
	while (p1[++i])
		r[i] = p1[i];
	j = -1;
	while (p2[++j])
		r[i++] = p2[j];
	r[i] = '\0';
	return (r);
}
