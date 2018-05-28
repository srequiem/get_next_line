/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <srequiem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:23:31 by srequiem          #+#    #+#             */
/*   Updated: 2018/05/28 19:10:19 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		riding_zone(char **line, char **str)
{
	char	*tmp;
	int		n;

	n = 0;
	if (*str && (n = ft_is_in(*str, '\n')) != -1)
	{
		*line = ft_strdupn(*str, n);
		tmp = ft_strdup(*str + n + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	return (0);
}

int		ft_read(int fd, char **str, char **line)
{
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	int		bytes;

	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (*str)
		{
			tmp = *str;
			*str = ft_strjoin(*str, buff);
			free(tmp);
		}
		else
			*str = ft_strdup(buff);
		if (riding_zone(line, str))
			return (1);
	}
	if (*str && bytes == 0 && *str[0] != '\0')
	{
		*line = ft_strdup(*str);
		*str = NULL;
		return (1);
	}
	return ((bytes == -1) ? -1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || fd > OPEN_MAX)
		return (-1);
	if (str[fd])
	{
		if (riding_zone(line, &str[fd]))
			return (1);
		else
			return (ft_read(fd, &str[fd], line));
	}
	else
		return (ft_read(fd, &str[fd], line));
	return (0);
}
/*
#include <stdio.h>
int		main(int argc, char **argv)
{
	char	*line = NULL;
	int		fd;
	int		ret;

	if (argc < 2)
	{
		ft_putstr("A Few Moments later...\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
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
	return (0);
}*/
