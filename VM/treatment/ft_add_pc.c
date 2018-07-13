/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 05:48:31 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/26 07:09:17 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_add_pc(t_env *e, t_process *father, short i)
{
	t_process	*tmp;
	t_process	*tmp2;
	int			k;

	k = 0;
	tmp = NULL;
	tmp2 = NULL;
	if (!(tmp = ft_memalloc(sizeof(t_process))))
		return (0);
	tmp->pc = father->pc + (short)i;
	tmp->pc = (tmp->pc < 0) ? MEM_SIZE + tmp->pc : tmp->pc;
	tmp->pc = tmp->pc % MEM_SIZE;
	tmp->waiting = father->waiting;
	tmp->to_exec = 0;
	tmp->lives_during_periode = father->lives_during_periode;
	tmp->carry = father->carry;
	tmp->from_pl = father->from_pl;
	while (k < REG_NUMBER)
	{
		tmp->reg[k] = father->reg[k];
		k++;
	}
	tmp->next = e->pc_list;
	e->pc_list = tmp;
	return (1);
}
