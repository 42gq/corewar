/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 04:04:39 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 04:10:23 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		mini_reg(t_env *e, int *start)
{
	if (e->stock[e->count + *start] != 'r')
		return (0);
	(*start)++;
	if (!ft_isdigit(e->stock[e->count + *start]))
		return (0);
	return (1);
}

void	mini_get_arg_dir(t_env *e, unsigned char *str, t_offset *t_off,
					int dir_size)
{
	unsigned int	dir_value;

	dir_value = ft_atoi(e->stock + t_off->offset + 1);
	if (dir_size == 0)
	{
		number_to_hex(dir_value, str + t_off->index_str);
		t_off->index_str += 4;
		t_off->size_ope += 4;
	}
	else
	{
		number_to_hex_size_two(dir_value, str + t_off->index_str);
		t_off->index_str += 2;
		t_off->size_ope += 2;
	}
}

void	get_args_dir(t_env *e, unsigned char *str, t_offset *t_off,
					int dir_size)
{
	int				i;

	i = 2;
	if (dir_size == 1)
		i = 0;
	if (e->stock[t_off->offset + 1] == LABEL_CHAR && e->stock[t_off->offset + 1]
			!= '-')
	{
		e->size_player -= 1;
		get_label(e, t_off->offset - e->count + 1, t_off->size_ope + 2 + i,
				dir_size);
		e->size_player += 1;
		t_off->size_ope += 2 + i;
		t_off->index_str += 2 + i;
	}
	else
		mini_get_arg_dir(e, str, t_off, dir_size);
}

void	get_args_ind(t_env *e, unsigned char *str, t_offset *t_off)
{
	unsigned int	ind_value;

	ind_value = 0;
	if (e->stock[t_off->offset] == LABEL_CHAR && e->stock[t_off->offset] != '-')
	{
		e->size_player -= 1;
		get_label(e, t_off->offset - e->count, t_off->size_ope + 2, 1);
		e->size_player += 1;
		t_off->size_ope += 2;
		t_off->index_str += 2;
	}
	else
	{
		ind_value = ft_atoi(e->stock + t_off->offset);
		number_to_hex_size_two(ind_value, str + t_off->index_str);
		t_off->index_str += 2;
		t_off->size_ope += 2;
	}
}

void	get_args_reg(t_env *e, unsigned char *str, t_offset *t_off)
{
	int				reg_number;

	reg_number = 0;
	reg_number = ft_atoi(e->stock + t_off->offset + 1);
	str[t_off->index_str] = ((reg_number << 24 & 0xff000000) >> 24 &
							0x000000ff);
	t_off->index_str += 1;
	t_off->size_ope += 1;
}
