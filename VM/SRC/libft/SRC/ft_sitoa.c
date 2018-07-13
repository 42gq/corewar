/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 01:38:53 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 06:48:56 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(signed short int n)
{
	int		negative;

	if (n < 0)
		negative = 1;
	else
		negative = 0;
	return (negative);
}

char		*ft_sitoa(signed short int n)
{
	signed short int	tmp;
	int					len;
	int					neg;
	char				*str;

	if (n == -32768)
		return (ft_strdup("-32768"));
	tmp = n;
	neg = ft_sign(n);
	len = (neg) ? 3 : 2;
	while (tmp /= 10)
		len++;
	if (!(str = malloc(sizeof(char) * len)))
		return (NULL);
	if (neg)
		n *= -1;
	str[--len] = '\0';
	while (len--)
	{
		str[len] = (n % 10 + 48);
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
