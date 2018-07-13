/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/28 02:14:55 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int				check_coding_byte(t_env *e, t_params *p, t_args_value args[3],
		t_process *pc)
{
	if (p->num_param == p->nb_params_max)
		return (p->bad_byte);
	p->arg_type = (p->coding_byte >> 6);
	if (p->arg_type == 3)
		p->arg_type = 4;
	if ((p->arg_type & g_op_tab[p->opcode].arg_type[p->num_param]) == 0)
		p->bad_byte = BAD_CODING_BYTE;
	if (p->num_param < p->nb_params_max)
	{
		p->coding_byte <<= 2;
		if (get_args_value(args, pc, e, p) == REG_INVALID)
			p->bad_byte = BAD_CODING_BYTE;
		p->num_param++;
		return (check_coding_byte(e, p, args, pc));
	}
	return (p->bad_byte);
}

int				ft_operations_sec(t_env *e, t_process *process,
		t_params par, t_args_value *args)
{
	if (g_op_tab[par.opcode].octal == 1)
	{
		par.bad_byte = 1;
		par.total_size += 1;
		if (((par.coding_byte = e->arena[(process->pc + 1) % MEM_SIZE]) == 0) ||
				(check_coding_byte(e, &par, args, process) == BAD_CODING_BYTE))
		{
			process->pc = (process->pc + par.total_size) % MEM_SIZE;
			return (0);
		}
	}
	else
	{
		par.total_size = (g_op_tab[par.opcode].dir_size) ? 2 : 4;
		if (par.total_size == 4)
			args[0].dir = read_nb_bytes(e, par.total_size, process, 1);
		else
			args[0].dir_short = read_nb_bytes(e, par.total_size, process, 1);
	}
	process->pc = process->pc % MEM_SIZE;
	g_op_tab[par.opcode].op(e, process, args);
	if (par.opcode + 1 != 9)
		process->pc += (par.total_size) + 1;
	process->pc = process->pc % MEM_SIZE;
	return (1);
}

int				ft_operations(t_env *e, t_process *process)
{
	t_params		par;
	t_args_value	args[3];

	init_t_args(args);
	init_t_params(&par);
	par.opcode = process->opcode - 1;
	process->opcode = 0;
	par.nb_params_max = g_op_tab[par.opcode].nb_param;
	return (ft_operations_sec(e, process, par, args));
}
