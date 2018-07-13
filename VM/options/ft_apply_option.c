/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 06:01:56 by gquerre           #+#    #+#             */
/*   Updated: 2018/05/03 07:35:38 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_load_dump(t_env *e, char *argv)
{
	int		k;
	char	*tmp;

	k = 0;
	tmp = NULL;
	e->dump_on = ft_atoi(argv);
	tmp = ft_itoa(e->dump_on);
	k = ft_strcmp(tmp, argv);
	ft_strdel(&tmp);
	if (e->dump_on < 1)
		return (0);
	return ((k) ? 0 : 1);
}

int	ft_apply_option(t_env *e, char *argv, int i)
{
	int		k;
	int		tmp;
	char	*nbr;

	tmp = e->option;
	e->option = 0;
	k = -1;
	while (argv[++k] != '\0')
		if (!ft_isdigit(argv[k]))
			return (0);
	if (tmp == 1)
		return (ft_load_dump(e, argv));
	else if (tmp == 2 && e->forced_nb_for_pl == 0)
	{
		e->forced_nb_for_pl = ft_atou(argv);
		nbr = ft_utoa_base(e->forced_nb_for_pl, 10);
		if (ft_strcmp(nbr, argv))
		{
			ft_strdel(&nbr);
			return (0);
		}
		ft_strdel(&nbr);
		return (1);
	}
	return (0);
}
