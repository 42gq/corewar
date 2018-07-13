/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 01:23:42 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 02:55:30 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	xozf_command(t_env *e, int i, int sl)
{
	if (ft_strncmp(e->stock + e->count + i, "xor", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 8, sl));
	if (ft_strncmp(e->stock + e->count + i, "or", 2) == 0 &&
		(e->stock[e->count + i + 2] > 126 ||
		e->stock[e->count + i + 2] < 33))
		return (operator_all(e, i + 2, 7, sl));
	if (ft_strncmp(e->stock + e->count + i, "zjmp", 4) == 0 &&
		(e->stock[e->count + i + 4] > 126 ||
		e->stock[e->count + i + 4] < 33))
		return (zjmp_operator(e, i + 4, sl));
	if (ft_strncmp(e->stock + e->count + i, "fork", 4) == 0 &&
		(e->stock[e->count + i + 4] > 126 ||
		e->stock[e->count + i + 4] < 33))
		return (fork_operator(e, i + 4, sl));
	return (0);
}

int	a_command(t_env *e, int i, int sl)
{
	if (ft_strncmp(e->stock + e->count + i, "add", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 4, sl));
	if (ft_strncmp(e->stock + e->count + i, "and", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 6, sl));
	if (ft_strncmp(e->stock + e->count + i, "aff", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 16, sl));
	return (0);
}

int	s_command(t_env *e, int i, int sl)
{
	if (ft_strncmp(e->stock + e->count + i, "st", 2) == 0 &&
		(e->stock[e->count + i + 2] > 126 ||
		e->stock[e->count + i + 2] < 33))
		return (operator_all(e, i + 2, 3, sl));
	if (ft_strncmp(e->stock + e->count + i, "sub", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 5, sl));
	if (ft_strncmp(e->stock + e->count + i, "sti", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 11, sl));
	return (0);
}

int	l_command(t_env *e, int i, int sl)
{
	if (e->stock[e->count + i + 1] == 'd' &&
		(e->stock[e->count + i + 2] > 126 ||
		e->stock[e->count + i + 2] < 33))
		return (operator_all(e, i + 2, 2, sl));
	if (ft_strncmp(e->stock + e->count + i, "live", 4) == 0 &&
		(e->stock[e->count + i + 4] > 126 ||
		e->stock[e->count + i + 4] < 33))
		return (live_operator(e, i + 4, sl));
	if (ft_strncmp(e->stock + e->count + i, "ldi", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 10, sl));
	if (ft_strncmp(e->stock + e->count + i, "lld", 3) == 0 &&
		(e->stock[e->count + i + 3] > 126 ||
		e->stock[e->count + i + 3] < 33))
		return (operator_all(e, i + 3, 13, sl));
	if (ft_strncmp(e->stock + e->count + i, "lldi", 4) == 0 &&
		(e->stock[e->count + i + 4] > 126 ||
		e->stock[e->count + i + 4] < 33))
		return (operator_all(e, i + 4, 14, sl));
	if (ft_strncmp(e->stock + e->count + i, "lfork", 5) == 0 &&
		(e->stock[e->count + i + 5] > 126 ||
		e->stock[e->count + i + 5] < 33))
		return (lfork_operator(e, i + 5, sl));
	return (0);
}

int	valid_command(t_env *e, int sl, int i)
{
	i = skip_label(e, sl);
	i += skip_space(e->stock + e->count + i);
	if (i < sl)
	{
		if (e->stock[e->count + i] == 'l')
			return (l_command(e, i, sl));
		else if (e->stock[e->count + i] == 's')
			return (s_command(e, i, sl));
		else if (e->stock[e->count + i] == 'a')
			return (a_command(e, i, sl));
		else if (e->stock[e->count + i] == 'o')
			return (xozf_command(e, i, sl));
		else if (e->stock[e->count + i] == 'x')
			return (xozf_command(e, i, sl));
		else if (e->stock[e->count + i] == 'z')
			return (xozf_command(e, i, sl));
		else if (e->stock[e->count + i] == 'f')
			return (xozf_command(e, i, sl));
		else if (e->stock[e->count + i] == COMMENT_CHAR)
			return (1);
		else
			return (0);
	}
	return (1);
}
