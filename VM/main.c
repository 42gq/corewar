/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:20:17 by gquerre           #+#    #+#             */
/*   Updated: 2018/08/23 14:03:20 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/corewar_vm.h"

t_op_info	g_op_tab[17] =
{
	{live, "live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{ld, "ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{st, "st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{add, "add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{sub, "sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{c_and, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{c_or, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{c_xor, "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{zjmp, "zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{ldi, "ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{sti, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{c_fork, "fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{lld, "lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{lldi, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{lfork, "lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{aff, "aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{NULL, 0, 0, {0}, 0, 0, 0, 0, 0}
};

int	main_two(t_env *e)
{
	if (e->forced_nb_for_pl)
		return (ft_error(e, 8));
	if (e->option > 0 || e->forced_nb_for_pl > 0)
		return (ft_error(e, 9));
	if (ft_init_process(e) == 0)
		return (ft_error(e, 5));
	if (e->visu == 1)
		if (ft_start_the_game_visu(e) == 0)
			e->visu = 2;
	if (ft_game_runner(e) == 0)
		return (ft_error(e, 6));
	if (ft_finish(e, 1) == 0)
		return (ft_error(e, 7));
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_env	*e;

	i = 0;
	if (!(e = ft_memalloc(sizeof(t_env))) || ft_create_arena(e) == 0)
		return (ft_error(e, 1));
	if (ft_how_many_pl(e, argc, argv) == 0)
		return (ft_error(e, 2));
	while (++i < argc)
	{
		if (e->option > 0)
		{
			if (ft_apply_option(e, argv[i], i) == 0)
				return (ft_error(e, 8));
		}
		else if (argv[i] && argv[i][0] == '-')
		{
			if (ft_options(e, argv[i]) == 0)
				return (ft_error(e, 3));
		}
		else if (ft_init_player(e, argv[i]) == 0)
			return (ft_error(e, 4));
	}
	return ((main_two(e)) ? 1 : 0);
}
