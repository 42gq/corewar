/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 08:20:36 by snedir            #+#    #+#             */
/*   Updated: 2018/05/01 08:21:03 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_clean_env(t_env *e)
{
	t_label		*tmp_stock;
	t_label		*tmp_label;

	tmp_stock = e->stock_label;
	tmp_label = e->lst_label;
	while (tmp_stock)
	{
		tmp_stock = tmp_stock->next;
		ft_strdel(&e->stock_label->name);
		ft_memdel((void **)&e->stock_label);
		e->stock_label = tmp_stock;
	}
	while (tmp_label)
	{
		tmp_label = tmp_label->next;
		ft_strdel(&e->lst_label->name);
		ft_memdel((void **)&e->lst_label);
		e->lst_label = tmp_label;
	}
	ft_memdel((void **)&e->player_buff);
	ft_strdel(&e->stock);
	ft_strdel(&e->name_file);
	ft_strdel(&e->name_player);
	ft_strdel(&e->comment);
	ft_memdel((void **)&e);
}
