/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/26 07:06:08 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void			init_t_args(t_args_value args[3])
{
	int				i;

	i = -1;
	while (++i < 3)
	{
		args[i].reg = 0;
		args[i].dir = 0;
		args[i].ind = 0;
		args[i].type = 0;
		args[i].dir_short = 0;
	}
}

void			init_t_params(t_params *params)
{
	params->nb_params_max = 0;
	params->num_param = 0;
	params->coding_byte = 0;
	params->total_size = 0;
	params->opcode = 0;
	params->arg_type = 0;
	params->bad_byte = 1;
}
