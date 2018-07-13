/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 04:03:34 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/28 06:44:36 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_end_visu(t_env *e)
{
	int	i;

	i = -1;
	e->visu = 0;
	if (e->vi)
	{
		while (++i < 7)
			if (COLOR_PAIR(i))
				attroff(COLOR_PAIR(i));
		if (e->vi->arena)
			wclear(e->vi->arena);
		if (e->vi->info)
			wclear(e->vi->info);
		if (e->vi->arena)
			delwin(e->vi->arena);
		if (e->vi->info)
			delwin(e->vi->info);
		free(e->vi);
	}
	endwin();
}
