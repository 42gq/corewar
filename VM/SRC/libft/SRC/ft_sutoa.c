/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:29:39 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 06:50:48 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizechars(unsigned short int i, int base)
{
	int		size;

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

char	*ft_sutoa(unsigned short int value, int base)
{
	int		i;
	char	*nbr;

	i = ft_sizechars(value, base);
	if (!(nbr = ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	nbr[i + 1] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + ((value % base > 9) ? 'a' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}
