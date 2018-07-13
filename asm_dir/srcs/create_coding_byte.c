/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coding_byte.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:42:24 by snedir            #+#    #+#             */
/*   Updated: 2018/05/02 04:09:22 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	fill_coding_byte(unsigned char *coding_byte, t_offset *t_off, int id)
{
	if (id == 0)
	{
		*coding_byte |= REG >> t_off->trileen;
		t_off->trileen += 2;
		t_off->next_separator = 1;
	}
	if (id == 1)
	{
		*coding_byte |= _DIR >> t_off->trileen;
		t_off->trileen += 2;
		t_off->next_separator = 1;
	}
	if (id == 2)
	{
		*coding_byte |= IND >> t_off->trileen;
		t_off->trileen += 2;
		t_off->next_separator = 1;
	}
}

void	fill_and_reg(t_env *e, unsigned char *coding_byte, t_offset *t_off,
						unsigned char *str)
{
	fill_coding_byte(coding_byte, t_off, 0);
	get_args_reg(e, str, t_off);
}

void	fill_and_ind(t_env *e, unsigned char *coding_byte, t_offset *t_off,
						unsigned char *str)
{
	fill_coding_byte(coding_byte, t_off, 2);
	get_args_ind(e, str, t_off);
}

int		create_coding_byte(t_env *e, t_offset *t_off, unsigned char opcode,
		unsigned char *str)
{
	unsigned char	coding_byte;

	t_off->trileen = 0;
	t_off->next_separator = 0;
	coding_byte = 0;
	while (e->stock[t_off->offset] != '\n' &&
		e->stock[t_off->offset] != COMMENT_CHAR)
	{
		if (e->stock[t_off->offset] == 'r' && t_off->next_separator == 0)
			fill_and_reg(e, &coding_byte, t_off, str);
		if (e->stock[t_off->offset] == DIRECT_CHAR &&
			t_off->next_separator == 0)
		{
			fill_coding_byte(&coding_byte, t_off, 1);
			get_args_dir(e, str, t_off, g_op_tab[opcode].dir_size);
		}
		if ((e->stock[t_off->offset] == '-' ||
		ft_isdigit(e->stock[t_off->offset]) ||
		e->stock[t_off->offset] == LABEL_CHAR) && t_off->next_separator == 0)
			fill_and_ind(e, &coding_byte, t_off, str);
		if (e->stock[t_off->offset] == SEPARATOR_CHAR && t_off->next_separator)
			t_off->next_separator = 0;
		t_off->offset += 1;
	}
	return (coding_byte);
}

void	menu_args_coding_byte(t_env *e, int start, unsigned char opcode)
{
	unsigned char	*str;
	t_offset		t_off;
	unsigned char	coding_byte;

	str = NULL;
	t_off.index_str = 0;
	t_off.offset = e->count + start;
	t_off.size_ope = 0;
	if (!(str = ft_memalloc(20)))
		ft_perror("");
	coding_byte = create_coding_byte(e, &t_off, opcode, str);
	add_command(e, &coding_byte, 1);
	add_command(e, str, t_off.size_ope);
	free(str);
}
