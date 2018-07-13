/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/25 08:03:44 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	ld(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int	parameter;

	if (args[0].type == 'd')
		parameter = args[0].dir;
	else
		parameter = read_nb_bytes(e, 4, process,
				ft_arg_neg_two(args[0].ind, IDX_MOD));
	process->reg[args[1].reg - 1] = parameter;
	if (parameter == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
