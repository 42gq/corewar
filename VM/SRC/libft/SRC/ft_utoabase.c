/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 03:54:28 by gquerre           #+#    #+#             */
/*   Updated: 2018/05/03 07:56:12 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizechar(unsigned int i, int base)
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

char	*ft_utoa_base(unsigned int value, int base)
{
	int		i;
	char	*nbr;

	i = ft_sizechar(value, base);
	if (!(nbr = ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i-- > 0)
	{
		nbr[i] = (value % base) + ((value % base > 9) ? 'a' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}
