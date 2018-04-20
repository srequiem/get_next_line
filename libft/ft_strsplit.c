/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srequiem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:19:08 by srequiem          #+#    #+#             */
/*   Updated: 2018/04/12 14:37:37 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nb_words(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static void		ft_cpy(char *dest, char const *src, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] == c && src[i])
		i++;
	if (nb_words(src, c) == 1)
	{
		while (src[i] != c && src[i])
			dest[j++] = src[i++];
	}
	while (src[i] != c && src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_iwords;
	int		i;
	int		j;
	char	**tab;

	if (!s)
		return (0);
	i = 0;
	nb_iwords = nb_words(s, c);
	if (!(tab = (char**)malloc((nb_iwords + 1) * sizeof(char*))))
		return (0);
	j = 0;
	while (i < nb_iwords)
	{
		if (!(tab[i] = (char*)malloc((ft_strlen(s) + 1) * sizeof(char*))))
			return (0);
		while (s[j] == c && s[j])
			j++;
		ft_cpy(tab[i], &s[j], c);
		while (s[j] != c && s[j])
			j++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
