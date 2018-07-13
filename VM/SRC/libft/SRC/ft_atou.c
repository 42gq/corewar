/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 05:34:56 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/31 05:38:51 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

unsigned int	ft_atou(char *str)
{
	unsigned int	res;
	int				i;

	res = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\n')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}
