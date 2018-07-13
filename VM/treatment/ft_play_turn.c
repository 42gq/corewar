/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play_turn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:42:08 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/26 06:54:23 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_load_waiting(t_env *e, t_process *proc)
{
	if ((proc->opcode = e->arena[proc->pc]) < 17 && e->arena[proc->pc] > 0)
	{
		proc->to_exec = 1;
		proc->waiting = g_op_tab[e->arena[proc->pc] - 1].nb_cycle - 2;
	}
	else
		proc->pc++;
	return (1);
}

int	ft_play_turn(t_env *e)
{
	t_process	*tmp;

	tmp = e->pc_list;
	e->very_last_flag = 0;
	while (tmp)
	{
		tmp->pc = tmp->pc % (MEM_SIZE);
		if (tmp->waiting == 0)
		{
			if (tmp->to_exec == 1)
			{
				if (!(ft_operations(e, tmp)))
					tmp->pc = (tmp->pc + 1) % MEM_SIZE;
				tmp->to_exec = 0;
			}
			else if (ft_load_waiting(e, tmp) == 0)
				return (0);
		}
		else
			tmp->waiting--;
		tmp->pc = tmp->pc % (MEM_SIZE);
		tmp = tmp->next;
	}
	return (1);
}
