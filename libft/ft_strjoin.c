/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:31:10 by srequiem          #+#    #+#             */
/*   Updated: 2018/05/03 11:52:06 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*str;
	unsigned int	len_tot;

	if (!s1 || !s2)
		return (0);
	len_tot = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	if (!(str = (char*)malloc((len_tot + 1) * sizeof(char))))
		return (0);
	ft_bzero(str, len_tot + 1);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}
