/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_the_game_visu.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:16:10 by gquerre           #+#    #+#             */
/*   Updated: 2018/05/02 05:54:34 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_start_the_game_visu(t_env *e)
{
	if (ft_fill_arena(e) == 0)
		return (0);
	if (ft_fill_info(e) == 0)
		return (0);
	start_color();
	init_pair(0, COLOR_WHITE, use_default_colors());
	init_pair(3, COLOR_RED, use_default_colors());
	init_pair(2, COLOR_BLUE, use_default_colors());
	init_pair(1, COLOR_GREEN, use_default_colors());
	init_pair(4, COLOR_YELLOW, use_default_colors());
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_CYAN, use_default_colors());
	wrefresh(e->vi->arena);
	wrefresh(e->vi->info);
	getch();
	return (1);
}
