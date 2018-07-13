/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 04:10:19 by gquerre           #+#    #+#             */
/*   Updated: 2017/05/15 04:10:22 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int res;
	int sign;

	while (*str == ' ' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\f' || *str == '\n')
		str++;
	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str) && *str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
