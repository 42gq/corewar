/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 05:22:45 by fdidelot          #+#    #+#             */
/*   Updated: 2018/04/26 06:39:08 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ld_operator(t_env *e, int start, int sl)
{
	int				i;
	int				size;
	unsigned char	*command;

	i = 0;
	start += skip_space(e->stock + e->count + start);
	if (!check_nb_param(e, start, sl, 0) || !valid_param(e, start, 0))
		return (0);
	size = 5;
	while (i < sl)
	{
		if (e->stock[e->count + start + i] == LABEL_CHAR)
			size = 7;
	}
	if (!(command = (unsigned char *)ft_memalloc(sizeof(unsigned char) * size)))
		ft_perror("malloc() failed.\n");
	command[0] = 0x02;
	return (1);
}
