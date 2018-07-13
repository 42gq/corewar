/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_neg_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:55:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/25 03:16:18 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

short	ft_arg_neg_two(unsigned short nb, int mod)
{
	short	res;

	res = 0;
	if (mod == 0)
		return ((short)nb);
	if (nb < 32768)
		return (nb % mod);
	else
		res = (short)nb;
	return ((res % mod));
}
