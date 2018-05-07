/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:23:31 by srequiem          #+#    #+#             */
/*   Updated: 2018/05/07 20:38:10 by srequiem         ###   ########.fr       */
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

	if (BUFF_SIZE < 1)
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
	if (bytes == -1)
	{
		//ft_strdel(str);
		return (-1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	if ((is_valid(fd, line, &str[fd]) == -1) || (riding_zone(fd, &str[fd]) == -1))
		return (-1);
	if (str[fd][i] && str[fd][i] != '\0')
	{
		while (str[fd][i] != '\n' && str[fd][i])
		{
			if (str[fd][i] == '\0')
				return (0);
			i++;
		}
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
/*
int		main(int argc, char **argv)
{
   int		fd;
   char		*line = NULL;
	int		ret;

	if (argc != 2)
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
	while (1)
	{}
	return (0);
}
*/
/*
int		main(int ac, char **av)
{
   	int fd = open(av[1], O_RDONLY);
   	int fd2 = open(av[2], O_RDONLY);
   	char *line;
   	int ret;

   	if (ac == 1)
   		return 0;
   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd2, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	   	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	ret = get_next_line(fd, &line);
	printf("[%d]:%s\n", ret, line);
	ft_strdel(&line);
	return (0);
}*/

