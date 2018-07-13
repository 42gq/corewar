/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:39:57 by fdidelot          #+#    #+#             */
/*   Updated: 2016/12/22 19:00:39 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *new;
	t_list *tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	map = f(lst);
	tmp = map;
	lst = lst->next;
	while (lst)
	{
		if (!(new = f(lst)))
			return (NULL);
		tmp->next = new;
		tmp = new;
		lst = lst->next;
	}
	return (map);
}
