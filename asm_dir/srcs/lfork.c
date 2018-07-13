/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:46:12 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 00:27:45 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	number_to_hex_size_two(unsigned int num, unsigned char *dest)
{
	dest[0] = (num << 16 & 0xff000000) >> 24 & 0x000000ff;
	dest[1] = (num << 24 & 0xff000000) >> 24 & 0x000000ff;
}

int		lfork_operator(t_env *e, int start, int sl)
{
	int				retatoi;
	unsigned char	*command;

	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 14) || !valid_param(e, start, 14))
		return (0);
	start++;
	if (!(command = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 3)))
		ft_perror("malloc() failed.\n");
	command[0] = 0x0f;
	if (e->stock[e->count + start] == LABEL_CHAR)
		get_label(e, start, 1, 1);
	else
	{
		retatoi = ft_atoi(e->stock + e->count + start);
		number_to_hex_size_two(retatoi, command + 1);
	}
	add_command(e, command, 3);
	free(command);
	return (1);
}
