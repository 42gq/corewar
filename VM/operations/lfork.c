/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:15:38 by snedir            #+#    #+#             */
/*   Updated: 2018/04/10 14:21:53 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	lfork(t_env *e, t_process *process, t_args_value args[3])
{
	ft_add_pc(e, process, ft_arg_neg_two(args[0].dir_short, MEM_SIZE));
}
