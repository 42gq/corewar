/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_visual.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 00:18:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/18 19:06:19 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void	ft_init_visual(t_env *e)
{
	e->vi->root = 0;
	e->vi->border = 0;
	e->vi->mx = 0;
	e->vi->my = 0;
	e->vi->color = 0;
	e->vi->speed = 0;
}

int		ft_visual(t_env *e)
{
	int	test;

	if (!(e->vi = ft_memalloc(sizeof(t_visu))))
		return (0);
	ft_init_visual(e);
	e->vi->root = sqrt(MEM_SIZE);
	test = MEM_SIZE % e->vi->root;
	if (test != 0 || e->vi->root < (e->nb_of_pl * 10))
		return (0);
	e->visu = 1;
	e->vi->border = 3;
	e->vi->mx = (3 * e->vi->root) + e->vi->border;
	e->vi->my = (e->vi->root) + 2;
	initscr();
	e->vi->arena = newwin(e->vi->my, e->vi->mx, 0, 0);
	e->vi->info = newwin(e->vi->my, 50, 0, e->vi->mx + 2);
	return (1);
}
