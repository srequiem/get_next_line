/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:23:31 by srequiem          #+#    #+#             */
/*   Updated: 2018/05/10 17:49:36 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <limits.h>

int			is_valid(int fd, char **line, char **str)
{
	if (fd < 0 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)ft_memalloc((BUFF_SIZE + 1) * sizeof(char))))
			return (-1);
	}
	return (0);
}

int			riding_zone(int fd, char **str)
{
	int		bytes;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	if (BUFF_SIZE <= 0)
		return (-1);
	if (**str)
		return (0);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		tmp = ft_strjoin(*str, buff);
		ft_strdel(str);
		*str = tmp;
	}
	return (bytes == -1 ? -1 : 0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	if ((is_valid(fd, line, &str[fd]) == -1) ||
		(riding_zone(fd, &str[fd]) == -1))
		return (-1);
	if (str[fd][i])
	{
		while (str[fd][i] != '\n' && str[fd][i])
			i++;
		*line = ft_strdupn(str[fd], i);
		tmp = str[fd];
		str[fd] = ft_strdup(str[fd] + i + 1);
		ft_strdel(&tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (0);
}

int		main(int argc, char **argv)
{
   int		fd;
   int		fd2;
   char		*line = NULL;
	int		ret;

	if (argc < 0)
	{
		ft_putstr("A Few Moments later...\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	if ((fd2 = open(argv[2], O_RDONLY)) < 0)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("[%d]:%s\n", ret, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	close(fd);

	while ((ret = get_next_line(fd2, &line)) > 0)
	{
		printf("[%d]:%s\n", ret, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	close(fd2);
	//while (1)
	//{}
	return (0);
}
