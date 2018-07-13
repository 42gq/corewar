/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 05:30:51 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/07 00:53:50 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	ft_print_hexa(unsigned char oct)
{
	char	*res;

	if (!(res = ft_ssutoa(oct, 16)))
		return (0);
	if (ft_strlen(res) > 2)
	{
		ft_strdel(&res);
		return (0);
	}
	if (ft_strlen(res) == 1)
		ft_putchar('0');
	ft_putstr(res);
	ft_strdel(&res);
	return (1);
}
