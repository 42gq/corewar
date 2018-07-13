/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 01:38:23 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 06:47:53 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_verif(long long int n)
{
	n += 1;
	if (n == -9223372036854775807)
		return (1);
	n -= 1;
	return (0);
}

static int	ft_sign(long long int n)
{
	int		negative;

	if (n < 0)
		negative = 1;
	else
		negative = 0;
	return (negative);
}

char		*ft_llitoa(long long int n)
{
	long long int	tmp;
	int				len;
	int				neg;
	char			*str;

	if (ft_verif(n))
		return (ft_strdup("-9223372036854775808"));
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
