/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjump.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 04:22:44 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/28 05:09:36 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	zjmp_operator(t_env *e, int start, int sl)
{
	int				retatoi;
	unsigned char	*command;

	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 8) || !valid_param(e, start, 8))
		return (0);
	start++;
	if (!(command = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 3)))
		ft_perror("malloc() failed.\n");
	command[0] = 0x09;
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
