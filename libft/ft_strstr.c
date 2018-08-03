/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 18:43:25 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/11 18:43:27 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_match(char *s1, char *s2)
{
	while (*s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (0);
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*string1;
	char	*string2;

	string1 = (char *)haystack;
	string2 = (char *)needle;
	if (*string2 == '\0' || string2 == NULL)
		return (string1);
	while (*string1)
	{
		if (is_match(string1, string2))
			return (string1);
		string1++;
	}
	return (NULL);
}
