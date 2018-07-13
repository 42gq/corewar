/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 03:07:14 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 06:10:13 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizechar(int i, int base)
{
	int size;

	size = 0;
	if (i == 0)
		return (1);
	else
		while (i != 0)
		{
			i = i / base;
			size++;
		}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		neg;
	char	*nbr;

	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	i = ft_sizechar(value, base);
	if (!(nbr = ft_memalloc(sizeof(char) * (i + neg + 1))))
		return (NULL);
	nbr[i + neg + 1] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + ((value % base > 9) ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}
