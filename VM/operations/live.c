/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:14:13 by snedir            #+#    #+#             */
/*   Updated: 2018/04/27 07:09:54 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	live(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int	parameter;
	int				i;

	i = -1;
	parameter = args[0].dir;
	while (++i < e->nb_of_pl)
	{
		if (e->players[i].id == parameter)
		{
			e->players[i].lives_periode++;
			e->players[i].total_lives++;
			e->players[i].last_live = e->cycles;
			e->very_last_flag += 1;
			e->players[i].very_last_flag = e->very_last_flag;
		}
	}
	process->lives_during_periode++;
	e->lives_periode++;
}
