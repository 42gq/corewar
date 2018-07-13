/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:15:23 by snedir            #+#    #+#             */
/*   Updated: 2018/04/25 04:12:54 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	lld(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned int	parameter;

	if (args[0].type == 'd')
		parameter = args[0].dir;
	else
		parameter = read_nb_bytes(e, 4, process,
				ft_arg_neg_two(args[0].ind, MEM_SIZE));
	process->reg[args[1].reg - 1] = parameter;
	if (parameter == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
