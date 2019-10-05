/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:24:35 by jfelty            #+#    #+#             */
/*   Updated: 2019/09/18 02:28:37 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BUFF_SIZE 4
#define MAX_FD 10240

/*
**	makes a new pointer variable and points it to the next new line character.
**	the characters in between are then passed into line using ft_strsub. then
**	the rest of the string is copied back into the str[fd] variable. 1 is
**	returned if a new line can be read, and 0 if End of File has been reached.
*/

int	ft_gnl(char **str, char **line, int fd)
{
	char *next;
	char *tmp;

	if (!(next = ft_strchr(str[fd], '\n')))
	{
		if (!*str[fd])
			return (0);
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		return (1);
	}
	next++;
	*line = ft_strsub(str[fd], 0, next - str[fd] - 1);
	tmp = ft_strdup(str[fd] + (next - str[fd]));
	free(str[fd]);
	str[fd] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (1);
}

/*
**	the variable static char *str[MAX_FD] is a multidimensional array which
**	contains a string all possible file descriptors. when a new file descriptor
**	is opened, the if (str[fd] = NULL) condition is validated and the while
**	loop populates the str variable. these variables are then passed into
**	ft_gnl, which parses the string by '\n' characters.
*/

int	get_next_line(int const fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char	*str[MAX_FD];

	tmp = NULL;
	if (!line || fd < 0 || fd > MAX_FD || read(fd, 0, 0) == -1)
		return (-1);
	if (str[fd] == NULL)
	{
		str[fd] = ft_strnew(0);
		while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[ret] = '\0';
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		if (ret == -1 || (ret == 0 && ft_strchr(buff, '\0') == buff))
			return (ret == -1 ? -1 : 0);
	}
	return (ft_gnl(str, line, fd));
}
