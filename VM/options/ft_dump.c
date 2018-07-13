/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 05:21:24 by gquerre           #+#    #+#             */
/*   Updated: 2018/05/02 06:49:16 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_dump(t_env *e)
{
	int	i;
	int	v;

	i = 0;
	if (e->visu > 0)
		ft_end_visu(e);
	while (i < MEM_SIZE)
	{
		v = 0;
		while (i < MEM_SIZE && v < WIDTH_DUMP)
		{
			ft_print_hexa(e->arena[i]);
			if (v < WIDTH_DUMP - 1)
				ft_putchar(' ');
			v++;
			i++;
		}
		ft_putchar('\n');
	}
	return (1);
}
