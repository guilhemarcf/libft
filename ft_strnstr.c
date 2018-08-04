/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:59:29 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/11 18:59:31 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_n_match(char *s1, char *s2, int n)
{
	while (*s2)
	{
		if ((*s1 == *s2) && (n > 0))
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (0);
	}
	return (1);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*string1;
	char	*string2;

	string1 = (char *)haystack;
	string2 = (char *)needle;
	if (*string2 == '\0' || string2 == NULL)
		return (string1);
	while (*string1 && len > 0)
	{
		if (is_n_match(string1, string2, len))
			return (string1);
		string1++;
		len--;
	}
	return (NULL);
}
