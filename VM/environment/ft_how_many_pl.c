/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_how_many_pl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 04:31:29 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/31 08:30:03 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_how_many_pl(t_env *e, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (e->option == 1)
			e->option = 0;
		else if (argv[i][0] != '\0' && argv[i][0] != '-')
			e->nb_of_pl++;
		else if (argv[i][0] != '\0' && argv[i][0] == '-' && argv[i][1] != 'v')
			e->option = 1;
		i++;
	}
	e->option = 0;
	if (e->nb_of_pl == 0 || e->nb_of_pl > MAX_PLAYERS)
		return (0);
	else if (!(e->players = (ft_memalloc(sizeof(t_player) * e->nb_of_pl))))
		return (0);
	return (1);
}
