/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 02:42:35 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 05:22:12 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	check_reg(t_env *e, int start)
{
	int	reg_val;

	if (!mini_reg(e, &start))
		return (0);
	reg_val = ft_atoi(e->stock + e->count + start);
	if (reg_val > 16 || reg_val < 1)
		return (0);
	while (ft_isdigit(e->stock[e->count + start]))
		start++;
	if (e->stock[e->count + start] != SEPARATOR_CHAR &&
		e->stock[e->count + start] != '\n' &&
		e->stock[e->count + start] != COMMENT_CHAR)
	{
		while (e->stock[e->count + start] != '\n')
		{
			if (ft_isprint(e->stock[e->count + start]))
			{
				if (e->stock[e->count + start] == COMMENT_CHAR)
					return (1);
				return (0);
			}
			start++;
		}
	}
	return (1);
}

int	valid_num(t_env *e, int start)
{
	int	i;
	int sl;

	i = 0;
	if (e->stock[e->count + start] == '-')
		start++;
	sl = size_line(e->stock, e->count + start);
	while (ft_isdigit(e->stock[e->count + start + i]))
		i++;
	if (e->stock[e->count + start + i] != SEPARATOR_CHAR &&
		e->stock[e->count + start + i] != '\n' &&
		e->stock[e->count + start + i] != COMMENT_CHAR)
	{
		while (i < sl)
		{
			if (ft_isprint(e->stock[e->count + start + i]))
			{
				if (e->stock[e->count + start + i] == COMMENT_CHAR && i > 0)
					return (1);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	valid_label(t_env *e, int start)
{
	int	i;
	int sl;

	i = 0;
	sl = size_line(e->stock, e->count + start);
	while (ft_isalnum(e->stock[e->count + start + i]) ||
		e->stock[e->count + start + i] == '_')
		i++;
	if (e->stock[e->count + start + i] != SEPARATOR_CHAR &&
		e->stock[e->count + start + i] != '\n' &&
		e->stock[e->count + start + i] != COMMENT_CHAR)
	{
		while (i < sl)
		{
			if (ft_isprint(e->stock[e->count + start + i]))
			{
				if (e->stock[e->count + start + i] == COMMENT_CHAR && i > 0)
					return (1);
				else
					return (0);
			}
			i++;
		}
	}
	return (1);
}

int	check_dir(t_env *e, int start)
{
	if (e->stock[e->count + start] != DIRECT_CHAR)
		return (0);
	start++;
	if (e->stock[e->count + start] == LABEL_CHAR)
		return (valid_label(e, start + 1));
	if (ft_isdigit(e->stock[e->count + start]) ||
		e->stock[e->count + start] == '-')
		return (valid_num(e, start));
	return (0);
}

int	check_ind(t_env *e, int start)
{
	if (e->stock[e->count + start] == LABEL_CHAR)
		return (valid_label(e, start + 1));
	if (ft_isdigit(e->stock[e->count + start]) ||
		e->stock[e->count + start] == '-')
		return (valid_num(e, start));
	return (0);
}
