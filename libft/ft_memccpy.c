/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:03:43 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/09 12:45:46 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*strdest;
	unsigned char	*strsrc;
	unsigned int	i;

	i = 0;
	strdest = (unsigned char *)dst;
	strsrc = (unsigned char *)src;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		if (strsrc[i] == (unsigned char)c)
			return ((void*)&strdest[++i]);
		i++;
	}
	return (NULL);
}
