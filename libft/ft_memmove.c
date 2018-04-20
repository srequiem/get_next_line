/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:57:24 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/09 18:01:28 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	int				n;
	unsigned char	*strsrc;
	unsigned char	*strdst;

	i = 0;
	n = len;
	strsrc = (unsigned char *)src;
	strdst = (unsigned char *)dst;
	if (src < dst)
	{
		while (--n > -1)
			strdst[n] = strsrc[n];
	}
	else
	{
		while (i < n)
		{
			strdst[i] = strsrc[i];
			i++;
		}
	}
	return (dst);
}
