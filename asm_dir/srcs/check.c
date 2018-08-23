/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 01:02:47 by fdidelot          #+#    #+#             */
/*   Updated: 2018/08/23 14:03:41 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	stock_label(t_env *e, int end)
{
	int	start;
	int	stock_end;

	stock_end = end;
	while (end > -1)
	{
		if ((!(e->stock[e->count + end] > 96 &&
			e->stock[e->count + end] < 123)) &&
			!ft_isdigit(e->stock[e->count + end]) &&
			e->stock[e->count + end] != '_')
			break ;
		end--;
	}
	if (end == -1)
		start = 0;
	else
		start = end + 1;
	while (end > -1)
	{
		if (e->stock[e->count + end] > 32)
			return (0);
		end--;
	}
	create_label_lst(e, start, stock_end);
	return (1);
}

int	check_label(t_env *e, int sl)
{
	int	i;

	i = 0;
	while (i < sl)
	{
		if (e->stock[e->count + i] == COMMENT_CHAR)
			return (1);
		if (e->stock[e->count + i] == LABEL_CHAR &&
			ft_isprint(e->stock[e->count + i - 1]) &&
			e->stock[e->count + i - 1] != DIRECT_CHAR &&
			e->stock[e->count + i - 1] != SEPARATOR_CHAR)
		{
			if (i == 0 || !stock_label(e, i - 1))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_char(t_env *e, int sl)
{
	int i;

	i = 0;
	while (i < sl)
	{
		if (e->stock[e->count + i] == COMMENT_CHAR)
			return (1);
		if ((!(e->stock[e->count + i] > 96 &&
			e->stock[e->count + i] < 123)) &&
			!ft_isdigit(e->stock[e->count + i]))
		{
			if (e->stock[e->count + i] > 33 &&
				e->stock[e->count + i] != LABEL_CHAR &&
				e->stock[e->count + i] != DIRECT_CHAR &&
				e->stock[e->count + i] != '_' &&
				e->stock[e->count + i] != SEPARATOR_CHAR &&
				e->stock[e->count + i] != '-')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_line(t_env *e, int sl)
{
	int	i;

	i = 0;
	if (sl == 0 || e->stock[e->count] == COMMENT_CHAR)
		return (1);
	if (!check_char(e, sl))
		return (0);
	if (!check_label(e, sl))
		return (0);
	if (!valid_command(e, sl, 0))
		return (0);
	return (1);
}
