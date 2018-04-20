/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 12:21:37 by macbook           #+#    #+#             */
/*   Updated: 2018/04/09 22:21:02 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*sup;
	t_list	*next_sup;

	sup = *alst;
	while (sup)
	{
		next_sup = sup->next;
		del(sup->content, sup->content_size);
		free(sup);
		sup = next_sup;
	}
	*alst = NULL;
}
