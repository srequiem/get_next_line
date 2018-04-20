/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 13:42:37 by macbook           #+#    #+#             */
/*   Updated: 2018/04/16 18:05:47 by srequiem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*end;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		if (lst->content)
			tmp = f(lst);
		if (!new)
		{
			new = tmp;
			end = new;
			new->next = NULL;
		}
		else
		{
			new->next = tmp;
			tmp->next = NULL;
			new = new->next;
		}
		lst = lst->next;
	}
	return (end);
}
