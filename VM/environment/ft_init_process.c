/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:02:45 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/27 06:14:38 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_save_pc(t_env *e, t_process *new, int i)
{
	int	k;

	k = 0;
	new->pc = i * MEM_SIZE / e->nb_of_pl;
	new->reg[0] = e->players[i].id;
	new->waiting = 0;
	new->lives_during_periode = 0;
	new->carry = 0;
	new->to_exec = 0;
	new->opcode = 0;
	new->from_pl = i + 1;
	while (++k < REG_NUMBER)
		new->reg[k] = 0;
	new->next = NULL;
}

int		ft_init_process(t_env *e)
{
	t_process	*tmp;
	int			i;
	int			k;

	i = 0;
	tmp = NULL;
	ft_save_pc(e, e->pc_list, 0);
	while (++i < e->nb_of_pl)
	{
		if (!(tmp = ft_memalloc(sizeof(t_process))))
			return (0);
		ft_save_pc(e, tmp, i);
		tmp->next = e->pc_list;
		e->pc_list = tmp;
	}
	return (1);
}
