/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 03:57:39 by gquerre           #+#    #+#             */
/*   Updated: 2018/08/15 02:45:06 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_fresh(t_env *e)
{
	t_process	*tmp;
	int			i;

	i = -1;
	if (e->pc_list)
	{
		tmp = e->pc_list;
		while (tmp)
		{
			tmp = e->pc_list->next;
			ft_memdel((void*)&e->pc_list);
			e->pc_list = tmp;
		}
	}
	ft_memdel((void*)&e->arena);
	ft_memdel((void*)&e->written_by);
	while (e->nb_of_pl <= 4 && ++i < e->nb_of_pl)
	{
		ft_strdel(&e->players[i].name);
		ft_strdel(&e->players[i].comment);
	}
	ft_memdel((void*)&e->players);
	ft_strdel(&e->winner_name);
	ft_memdel((void*)&e);
}

int		ft_fight_under_the_moon(t_env *e, int i)
{
	if (e->players[i].last_live > e->winner_value)
	{
		e->winner_value = e->players[i].last_live;
		e->winner_flag = e->players[i].very_last_flag;
		if (e->winner_name)
			free(e->winner_name);
		if ((e->winner_name = ft_strdup(e->players[i].name)) == 0)
			return (0);
		e->winner_num_player = e->players[i].num_player;
	}
	else if ((e->players[i].last_live == e->winner_value) &&
			((e->players[i].very_last_flag > e->winner_flag) ||
			(e->winner_flag == -1)))
	{
		e->winner_value = e->players[i].last_live;
		e->winner_flag = e->players[i].very_last_flag;
		if (e->winner_name)
			free(e->winner_name);
		if ((e->winner_name = ft_strdup(e->players[i].name)) == 0)
			return (0);
		e->winner_num_player = e->players[i].num_player;
	}
	return (1);
}

int		ft_claim_winner(t_env *e)
{
	int	i;

	i = 0;
	while (i < e->nb_of_pl)
	{
		if (ft_fight_under_the_moon(e, i) == 0)
			return (0);
		i++;
	}
	ft_putstr("The Winner is ");
	ft_putchar('"');
	ft_putstr(e->winner_name);
	ft_putchar('"');
	ft_putstr(" Player ");
	ft_putnbr(e->winner_num_player);
	return (1);
}

int		ft_finish(t_env *e, int i)
{
	if (e->visu > 0)
		ft_end_visu(e);
	if (i == 1)
		if (ft_claim_winner(e) == 0)
			return (0);
	ft_fresh(e);
	return (1);
}
