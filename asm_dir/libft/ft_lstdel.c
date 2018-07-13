/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:22:58 by fdidelot          #+#    #+#             */
/*   Updated: 2016/12/22 18:34:22 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *lst_next;

	lst = *alst;
	while (lst)
	{
		lst_next = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lst_next;
	}
	*alst = NULL;
}
