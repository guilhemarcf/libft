/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:25:14 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/12 20:25:15 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*p1;
	char	*p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 != NULL && s2 == NULL)
		return (0);
	else if (s1 == NULL && s2 != NULL)
		return (0);
	else if (ft_strncmp(p1, p2, n) == 0)
		return (1);
	else
		return (0);
}
