/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:23:31 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/20 19:16:40 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		bytes;
	char	buff[BUFF_SIZE + 1];

	(void)line;
	if (fd < 0)
		return (-1);

	while ((bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bytes] = '\0';
		if (ft_strcmp(buff, "\n") == 0)
			break;
		ft_putstr(buff);	
	}
	return (1);
}

#include <stdio.h>
int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	
	if (argc != 2)
	{
		ft_putstr("A Few Moments later...\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (0);
	get_next_line(fd, &line);
	return (0);
}
