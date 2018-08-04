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

static char	*ft_make_line(char **ln_kpr, int fd)
{
	char	*temp;
	char	*ret;
	int		i;

	i = -1;
	ret = NULL;
	while (ln_kpr[fd][++i])
		if (ln_kpr[fd][i] == '\n' || ln_kpr[fd][i] == '\4')
			break ;
	temp = ln_kpr[fd];
	ret = ft_strsub(ln_kpr[fd], 0, i);
	if (ln_kpr[fd][i] == '\n' && ln_kpr[fd][i + 1] != '\0')
	{
		ln_kpr[fd] = ft_strsub(ln_kpr[fd], i + 1,
								ft_strlen(ln_kpr[fd]) - i);
		ft_strdel(&temp);
	}
	else
		ft_strdel(&ln_kpr[fd]);
	return (ret);
}

static void	ft_finalize(char **ln_kpr, int fd)
{
	char	*temp;

	if (ln_kpr[fd][ft_strlen(ln_kpr[fd]) - 1] != '\n')
	{
		temp = ln_kpr[fd];
		ln_kpr[fd] = ft_strjoin(ln_kpr[fd], "\4");
		ft_strdel(&temp);
	}
}

static void	ft_add_buff(char **ln_kpr, int fd, char *buff)
{
	char	*temp;

	temp = ln_kpr[fd];
	ln_kpr[fd] = ft_strjoin(ln_kpr[fd], buff);
	ft_strdel(&temp);
}

static int	read_to_buff(char **ln_kpr, int fd)
{
	char			buff[BUFF_SIZE + 1];
	int				byte_count;
	int				flag;

	flag = 0;
	byte_count = 0;
	while ((byte_count = read(fd, buff, BUFF_SIZE)) > 0)
	{
		flag = 1;
		buff[byte_count] = '\0';
		ft_add_buff(ln_kpr, fd, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (byte_count == 0)
		if (ln_kpr[fd])
			if (ln_kpr[fd][ft_strlen(ln_kpr[fd]) - 1] != '\n')
				ft_finalize(ln_kpr, fd);
	if (byte_count < 0)
		return (-1);
	if (flag == 0 && byte_count == 0)
		return (0);
	return (byte_count);
}

int			get_next_line(const int fd, char **line)
{
	static char		*ln_kpr[MAX_FD];
	int				byte_count;

	byte_count = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	if (ln_kpr[fd] != NULL && (ft_strchr(ln_kpr[fd], '\n') ||
								ft_strchr(ln_kpr[fd], '\4')))
		*line = ft_make_line(ln_kpr, fd);
	else
	{
		if ((byte_count = read_to_buff(ln_kpr, fd)) == 0)
		{
			if (ln_kpr[fd] && ft_strchr(ln_kpr[fd], '\4'))
			{
				*line = ft_make_line(ln_kpr, fd);
				return (1);
			}
			return (0);
		}
		if (byte_count < 0)
			return (-1);
		*line = ft_make_line(ln_kpr, fd);
	}
	return (1);
}
