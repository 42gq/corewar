/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 01:27:44 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 04:09:53 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	skip_param(t_env *e, int start, int num_p)
{
	int i;
	int	p;

	i = 0;
	p = 1;
	while (p < num_p)
	{
		if (e->stock[e->count + start + i] == SEPARATOR_CHAR)
			p++;
		i++;
	}
	return (i);
}

int	check_param(t_env *e, int start, t_arg_type type, int num_p)
{
	start += skip_param(e, start, num_p + 1);
	start += skip_space(e->stock + e->count + start);
	if (type == 1)
		return (check_reg(e, start));
	if (type == 2)
		return (check_dir(e, start));
	if (type == 4)
		return (check_ind(e, start));
	if (type == 3)
		return (check_dir(e, start) || check_reg(e, start));
	if (type == 5)
		return (check_reg(e, start) || check_ind(e, start));
	if (type == 6)
		return (check_dir(e, start) || check_ind(e, start));
	if (type == 7)
	{
		return (check_dir(e, start) || check_reg(e, start) ||
				check_ind(e, start));
	}
	return (1);
}

int	valid_param(t_env *e, int start, int n_op)
{
	int	i;

	i = 0;
	while (i < g_op_tab[n_op].nb_param)
	{
		if (!check_param(e, start, g_op_tab[n_op].arg_type[i], i))
			return (0);
		i++;
	}
	return (1);
}

int	check_nb_param(t_env *e, int start, int sl, int n_op)
{
	int	param;

	param = 1;
	while (start < sl && e->stock[e->count + start] != COMMENT_CHAR)
	{
		if (e->stock[e->count + start] == SEPARATOR_CHAR)
			param++;
		start++;
	}
	if (param != g_op_tab[n_op].nb_param)
		return (0);
	return (1);
}

int	size_line(char *stock, int count)
{
	int size;

	size = 0;
	while (stock[size + count] != '\n' && stock[size + count] != '\0')
		size++;
	return (size);
}
