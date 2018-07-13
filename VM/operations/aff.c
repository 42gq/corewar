/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 06:15:44 by snedir            #+#    #+#             */
/*   Updated: 2018/04/27 01:17:02 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../VM/includes/corewar_vm.h"

void	aff(t_env *e, t_process *process, t_args_value args[3])
{
	unsigned char c;

	c = process->reg[args[0].reg - 1] % 256;
	if (c < 128 && c > 47)
		write(1, &c, 1);
}
