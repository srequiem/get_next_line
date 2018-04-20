/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 19:36:04 by macbook           #+#    #+#             */
/*   Updated: 2018/04/09 14:21:45 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = -1;
	if (n == 0)
		return (0);
	while (++i < n - 1 && s1[i] && s2[i] && (s1[i] == s2[i]))
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
