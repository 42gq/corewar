/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 03:29:47 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 06:51:07 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizecharss(unsigned char i, int base)
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

char	*ft_ssutoa(unsigned char value, int base)
{
	int		i;
	char	*nbr;

	i = ft_sizecharss(value, base);
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
