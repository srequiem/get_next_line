/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:23:31 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/30 21:30:43 by macbook          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_valid(int fd, char ** line, char **str)
{
	if (fd < -1 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc((BUFF_SIZE + 1) * sizeof(char))))
			return (-1);
	}
	return (0);
}

char		*riding_zone(int fd, char *str)
{
	int	bytes;
	char	buff[BUFF_SIZE + 1];

	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

#include <stdio.h>
int		get_next_line(const int fd, char **line)
{
	static char	*str;
	int		i;

	i = 0;
	if (is_valid(fd, line, &str) == -1)
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
	str = riding_zone(fd, str);
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
		{
			i++;
		}
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			(*line) = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
		*line = ft_strdup("");	
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char		*line;
	int		i;

	i = -1;
	if (argc != 2)
	{
		ft_putstr("A Few Moments later...\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	while (++i < 5 )
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
	}
	//get_next_line(fd, &line);
	return (0);
}
