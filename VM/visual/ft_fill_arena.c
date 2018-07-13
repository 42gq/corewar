/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 03:41:03 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/27 00:39:24 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#include "../includes/corewar_vm.h"

void	ft_choose_color(t_env *e, int cmp)
{
	unsigned char	tmp;
	t_process		*pc;

	pc = e->pc_list;
	while (pc)
	{
		if (pc->pc == cmp)
		{
			wattron(e->vi->arena, COLOR_PAIR(5));
			wprintw(e->vi->arena, "%.2x", e->arena[cmp]);
			wattroff(e->vi->arena, COLOR_PAIR(5));
			return ;
		}
		pc = pc->next;
	}
	tmp = e->written_by[cmp];
	wattroff(e->vi->arena, COLOR_PAIR((int)tmp));
	wattron(e->vi->arena, COLOR_PAIR((int)tmp));
	wprintw(e->vi->arena, "%.2x", e->arena[cmp]);
	wattroff(e->vi->arena, COLOR_PAIR((int)tmp));
}

int		ft_fill_arena(t_env *e)
{
	int				i;
	int				j;
	int				cmp;

	cmp = 0;
	i = 1;
	j = 1;
	box(e->vi->arena, 0, 0);
	while (j < e->vi->my - 1 && cmp < MEM_SIZE)
	{
		while (i < e->vi->mx - 2 && cmp < MEM_SIZE)
		{
			wmove(e->vi->arena, j, i);
			wprintw(e->vi->arena, " ");
			ft_choose_color(e, cmp);
			i += 3;
			cmp++;
		}
		j++;
		i = 1;
	}
	return (1);
}
