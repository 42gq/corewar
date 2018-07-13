/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 05:26:10 by fdidelot          #+#    #+#             */
/*   Updated: 2017/04/28 23:17:42 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(int nb, int base)
{
	char	*str;
	int		i;
	char	*val;

	str = malloc(sizeof(char) * 66);
	val = ft_strdup("0123456789abcdef");
	i = 0;
	while (nb / base)
	{
		str[i] = val[nb % base];
		nb /= base;
		i++;
	}
	str[i] = val[nb % base];
	str[i + 1] = '\0';
	free(val);
	return (ft_strrev(str));
}
