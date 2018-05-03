/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:57:39 by srequiem          #+#    #+#             */
/*   Updated: 2018/05/03 11:58:00 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_strdupn(char *str, int n)
{
	char    *res;
	int     i;

	i = 0;
	if (!(res = (char*)malloc((n + 1) * sizeof(char))))
		return (0);
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
