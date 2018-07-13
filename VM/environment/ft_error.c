/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 05:46:54 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/28 07:18:26 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_error(t_env *e, int i)
{
	if (i != 7)
		ft_finish(e, 0);
	if (i == 1)
		ft_putstr("Error.\nMalloc of environment have failed\n");
	else if (i == 2)
		ft_putstr("Error.\nWrong number of players\n");
	else if (i == 3)
		ft_putstr("Error.\nWrong option input\n");
	else if (i == 4)
		ft_putstr("Error.\nChampion read failed\n");
	else if (i == 5)
		ft_putstr("Error.\nProcess initialization failed\n");
	else if (i == 6)
		ft_putstr("Error.\nGame_is_Over\n");
	else if (i == 7)
		ft_putstr("Error.\nFinishing function failed\n");
	else if (i == 8)
		ft_putstr("Error.\nWrong options, try again\n");
	else if (i == 9)
		ft_putstr("Error.\nwat the else\n");
	return (1);
}
