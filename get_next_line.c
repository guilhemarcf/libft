/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcaixeta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:15:45 by gcaixeta          #+#    #+#             */
/*   Updated: 2018/07/31 13:15:48 by gcaixeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function will just add buffers to the existing line being read from
** that fd.
*/

static void	buff_add(char *buff, char **ln_kpr, int fd)
{
	char	*temp;

	temp = ln_kpr[fd];
	ln_kpr[fd] = ft_strjoin(ln_kpr[fd], buff);
	ft_strdel(&temp);
}

/*
** This funtions will look for the occurence of line ending chars,
** and return the index in which they appear so that it can assign a fresh
** string with the line to the pointer given. If it finds a newline that is not
** followed by the end of the file, it removes the already assigned part of data
** and restarts after the last line terminator character.
** If it stops for anything but a new line, that means that the file was fully
** delivered and we can simply delete the data string that was storing part of
** it for future concatenation.
*/

static int	make_line(char **line, char **ln_kpr, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (ln_kpr[fd][i] != '\n' && ln_kpr[fd][i] != '\0')
		i++;
	*line = ft_strsub(ln_kpr[fd], 0, i);
	if (ln_kpr[fd][i] == '\n' && ln_kpr[fd][i + 1] != '\0')
	{
		temp = ln_kpr[fd];
		ln_kpr[fd] = ft_strsub(ln_kpr[fd], i + 1, ft_strlen(ln_kpr[fd]));
		ft_strdel(&temp);
	}
	else
		ft_strdel(&ln_kpr[fd]);
	return (1);
}

/*
** This function reads buffers to the line keeper array and make sure to
** signal if the file is over. If the read function returns zero from
** reading the end of file but there is still stuff in the line, it will
** call make_line to deliver that.
** If it just returns 0 without entering the loop, it should return 0.
** It the file descriptor can't be read, returns -1.
*/

static int	read_line(char **line, char **ln_kpr, int fd)
{
	int		numbyte;
	char	buff[BUFF_SIZE + 1];

	while ((numbyte = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[numbyte] = '\0';
		buff_add(buff, ln_kpr, fd);
		if (ft_strchr(ln_kpr[fd], '\n'))
			break ;
	}
	if (numbyte == 0)
	{
		if (ln_kpr[fd] != NULL)
			return (make_line(line, ln_kpr, fd));
		else
			return (0);
	}
	if (numbyte < 0)
		return (-1);
	return (make_line(line, ln_kpr, fd));
}

/*
** First I check if the file descriptor and the pointer to the line are valid.
** If they are, I check for the existance of data already stored.
** If there is data stored and among the data there are any of the ending
** characters, I return the function make_line, which will deliver the line
** there stored and the final integer.
** Otherwise, that will mean that either there is no data or the data there
** is incomplete, so I return the function read_line, which will either
** read more of the file and return make_line, or return an error, or return
** zero.
*/

int			get_next_line(const int fd, char **line)
{
	static char		*ln_kpr[MAX_FD];

	if (fd < 0 || line == NULL || fd > MAX_FD - 1)
		return (-1);
	if (ln_kpr[fd] != NULL && ft_strchr(ln_kpr[fd], '\n'))
		return (make_line(line, ln_kpr, fd));
	else
		return (read_line(line, ln_kpr, fd));
}
