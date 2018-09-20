/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acqinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 09:48:00 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/23 09:48:28 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** add_buff_array takes the auxiliary buffer and transfers it's contents to
** the array that will be returned, and ends it with a nul-terminator.
*/

static void	add_buff_array(char *buff, char *array)
{
	static size_t		i = 0;

	ft_strcpy(array + i, buff);
	i += AUX_BUFFER_SIZE;
	array[i - 1] = '\0';
}

/*
** input_acquire reads from a file descriptor and returns a string containing
** the info read. It does that by starting with a string with the size of the
** macro AUX_BUFFER_SIZE, which will transfer that to a bigger array, of size
** macro MAIN_BUFFER_SIZE, which can be reallocated to successively bigger
** arrays before returning the complete string read from the file.
*/

char		*ft_acqinput(int fd)
{
	char	buff[AUX_BUFFER_SIZE];
	int		rd;
	char	*array;
	int		max_size;
	int		byte_c;

	max_size = MAIN_BUFFER_SIZE;
	array = malloc(sizeof(*array) * (max_size + 1));
	if (array == NULL)
		return (NULL);
	rd = 1;
	byte_c = 0;
	while (rd != 0)
	{
		rd = read(fd, &buff, AUX_BUFFER_SIZE);
		buff[rd] = '\0';
		if (rd != 0)
		{
			if (byte_c >= max_size - AUX_BUFFER_SIZE - 2)
				array = ft_incr_n_trans(array, &max_size);
			add_buff_array(buff, array);
			byte_c = byte_c + rd;
		}
	}
	return (array);
}
