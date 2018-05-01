/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:23:31 by srequiem          #+#    #+#             */
/*   Updated: 2018/05/01 18:27:54 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			is_valid(int fd, char ** line, char **str)
{
	if (fd < 0 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc((BUFF_SIZE + 1) * sizeof(char))))
			return (-1);
	}
	return (0);
}

#include <stdio.h>

int			riding_zone(int fd, char **str)
{
	int		bytes;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;
	
	if (BUFF_SIZE < 1)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		tmp = ft_strjoin(*str, buff);
		ft_strdel(str);
		*str = tmp;
		//ft_strdel(&tmp);
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
	static char	*str;
	int			i;

	i = 0;
	if (is_valid(fd, line, &str) == -1)
		return (-1);
	//if (*str)
	//	ft_strcpy(*line, str);
	if (riding_zone(fd, &str) == -1)
		return (-1);
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
		{
			(*line) = ft_strdup("");
			str = &str[i + 1];
		}
		else
		{
			(*line) = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}
/*
int		main(int argc, char **argv)
{
	int		fd;
	char		*line;

	if (argc != 2)
	{
		ft_putstr("A Few Moments later...\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	while (1)
		;
	return (0);
}*/
