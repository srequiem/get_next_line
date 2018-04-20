/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:54:02 by macbook           #+#    #+#             */
/*   Updated: 2018/04/09 14:17:26 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*res;

	res = 0;
	i = 0;
	if (needle[i] == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			res = (char*)haystack + i;
			while (haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return (res);
				j++;
			}
			res = 0;
		}
		i++;
	}
	return (0);
}
