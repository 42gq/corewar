/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:13:03 by snedir            #+#    #+#             */
/*   Updated: 2018/04/10 14:47:07 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	c_fork(t_env *e, t_process *process, t_args_value args[3])
{
	ft_add_pc(e, process, ft_arg_neg_two(args[0].dir_short, IDX_MOD));
}
