/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:04:06 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/09 14:14:37 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			len_dst;

	i = 0;
	j = 0;
	len_dst = ft_strlen(dst);
	if (size > 0)
	{
		while (dst[i] && i < size)
			i++;
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
	}
	if (size != 0 && size >= len_dst)
		dst[i] = '\0';
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + len_dst);
}
