/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 04:37:46 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/28 05:07:50 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	fork_operator(t_env *e, int start, int sl)
{
	int				retatoi;
	unsigned char	*command;

	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 11) || !valid_param(e, start, 11))
		return (0);
	start++;
	if (!(command = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 3)))
		ft_perror("malloc() failed.\n");
	command[0] = 0x0c;
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
