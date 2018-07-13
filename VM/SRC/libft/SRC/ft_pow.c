/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/29 08:19:10 by gquerre           #+#    #+#             */
/*   Updated: 2017/07/31 04:14:43 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pow(int value, int pow)
{
	int tmp;
	int	neg;

	neg = 0;
	tmp = 1;
	if (pow < 0)
	{
		pow *= -1;
		neg = 1;
	}
	while (pow > 0)
	{
		tmp *= value;
		pow--;
	}
	if (neg == 1)
		tmp = 1 / tmp;
	return (tmp);
}
