/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_runner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 01:34:47 by gquerre           #+#    #+#             */
/*   Updated: 2018/05/03 07:18:32 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int		ft_free_process(t_env *e, t_process *pc, int i)
{
	t_process	*tmp;
	t_process	*tmp_bis;

	tmp = NULL;
	tmp_bis = NULL;
	if (i == 0)
	{
		tmp = (e->pc_list->next) ? e->pc_list->next : NULL;
		free(e->pc_list);
		e->pc_list = (tmp) ? tmp : NULL;
	}
	else if (i == -1)
	{
		tmp = pc;
		tmp_bis = tmp->next->next;
		free(tmp->next);
		tmp->next = tmp_bis;
	}
	return ((e->pc_list) ? 1 : 2);
}

int		ft_clean_process_list(t_env *e)
{
	t_process	*tmp;
	int			i;
	int			ret;

	ret = 1;
	i = 0;
	tmp = e->pc_list;
	while (tmp)
	{
		if (tmp->lives_during_periode == 0)
		{
			ret = ft_free_process(e, tmp, i);
			tmp = e->pc_list;
		}
		else
		{
			if (tmp->next && tmp->next->lives_during_periode == 0)
				ret = ft_free_process(e, tmp, -1);
			else
				tmp = tmp->next;
			i++;
		}
	}
	return (ret);
}

int		ft_maj(t_env *e, int i)
{
	t_player	*tmp;
	int			k;

	k = 0;
	if (!(e->pc_list))
		return (0);
	tmp = e->players;
	if (i == 1)
	{
		e->cycles_to_die = e->cycles_to_die - CYCLE_DELTA;
		e->checks_done = 0;
	}
	else
		e->checks_done++;
	e->lives_periode = 0;
	e->cycles_periode = 0;
	while (k < e->nb_of_pl)
	{
		tmp[k].lives_periode = 0;
		k++;
	}
	return ((e->cycles_to_die > 0) ? 1 : 2);
}

int		ft_up_periode(t_env *e)
{
	t_process	*tmp;
	int			a;

	a = 0;
	if ((a = ft_clean_process_list(e)) == 0 || a == 2)
		return (a);
	tmp = e->pc_list;
	while (tmp)
	{
		tmp->lives_during_periode = 0;
		tmp = tmp->next;
	}
	if (e->visu == 1)
	{
		wclear(e->vi->info);
		wclear(e->vi->arena);
	}
	if (e->lives_periode >= NBR_LIVE || e->checks_done >= MAX_CHECKS)
		a = ft_maj(e, 1);
	else
		a = ft_maj(e, 2);
	return (a);
}

int		ft_game_runner(t_env *e)
{
	int	a;

	a = 0;
	while (e->pc_list)
	{
		while (e->pc_list && e->cycles_periode < e->cycles_to_die &&
				ft_keypad(e, unix_text_kbhit()))
		{
			if (ft_play_turn(e) == 0)
				return (0);
			if (e->visu == 1)
				if (ft_maj_visu(e) == 0)
					return (0);
			if (e->visu == 1)
				usleep(FREQ + e->vi->speed);
			if (e->cycles == e->dump_on)
				return (ft_dump(e));
			e->cycles_periode++;
			e->cycles++;
		}
		if (e->cycles_periode >= e->cycles_to_die)
			if ((a = ft_up_periode(e)) == 0 || a == 2)
				return (a);
	}
	return (1);
}
