/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj_visu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 02:19:28 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/30 13:54:04 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_maj_visu(t_env *e)
{
	if (ft_fill_arena(e) == 0 || ft_fill_info(e) == 0)
		return (0);
	move(e->vi->my, 0);
	clrtoeol();
	wrefresh(e->vi->arena);
	wrefresh(e->vi->info);
	refresh();
	if (e->cycles == 1)
		getch();
	return (1);
}
