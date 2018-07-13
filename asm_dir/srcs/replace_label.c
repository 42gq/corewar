/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 01:19:01 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 07:29:50 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	put_label_into_buff(unsigned char *buff, int pos,
							unsigned int val, int size_dir)
{
	if (size_dir == 2)
		number_to_hex_size_two(val, buff + pos);
	else if (size_dir == 4)
		number_to_hex(val, buff + pos - 2);
	else
		ft_perror("WHATTHEFYCYJEDKEDGIGIUGWDPWDGOOUHDOBOUDJWOJDNWO\n");
}

int		replace_label(t_env *e)
{
	t_label	*tmp;
	t_label	*stock;
	int		label_exist;

	stock = e->stock_label;
	while (stock)
	{
		label_exist = 0;
		tmp = e->lst_label;
		while (tmp)
		{
			if (ft_strcmp(stock->name, tmp->name) == 0)
			{
				put_label_into_buff(e->player_buff,
						stock->placement + stock->deca,
						tmp->placement - stock->placement, stock->dir_size);
				label_exist = 1;
			}
			tmp = tmp->next;
		}
		if (!label_exist)
			return (0);
		stock = stock->next;
	}
	return (1);
}
