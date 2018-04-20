/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:21 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/09 14:09:40 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned int	i;

	i = 0;
	tmp = (unsigned char*)s;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void*)&tmp[i]);
		i++;
	}
	return (0);
}
