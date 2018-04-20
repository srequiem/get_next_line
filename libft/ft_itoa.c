/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:48:38 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/09 11:32:37 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		minus;

	minus = n;
	i = ft_len_int(n) - 1;
	if (!(res = (char*)malloc((ft_len_int(n) + 1) * sizeof(char))))
		return (0);
	res[i + 1] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n *= -1;
	while (i >= 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	if (minus < 0)
		res[0] = '-';
	return (res);
}
