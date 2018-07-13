/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp_w_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 04:15:37 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/16 13:55:02 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_comp_with_pl(t_env *e, t_process *pro)
{
	int				i;
	unsigned int	nb;
	int				j;

	i = 0;
	while (i < e->nb_of_pl)
	{
		nb = 0;
		j = -1;
		while (++j < INT_SIZE)
		{
			nb += e->arena[pro->pc + j] * ft_pow(256, (INT_SIZE - (j + 1)));
		}
		if (nb == e->players[i].id)
			return (i + 1);
		i++;
	}
	return (0);
}
