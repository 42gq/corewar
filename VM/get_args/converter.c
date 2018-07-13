/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snedir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 05:15:24 by snedir            #+#    #+#             */
/*   Updated: 2018/04/26 07:05:43 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

void			set_string(unsigned char *bin_num, int index,
		unsigned char ins)
{
	int				limit;
	int				i;

	i = index - 1;
	limit = 8;
	while (--limit >= 0)
	{
		bin_num[i] = ins;
		i--;
	}
}

void			dec_to_bin(int dec, unsigned char *bin_num,
		int index, int size)
{
	int				i;
	int				limit;

	i = index - 1;
	limit = 8;
	if (dec == 0)
		set_string(bin_num, index, '0');
	while (dec > 0 && i >= 0)
	{
		if (dec % 2 == 0)
			bin_num[i] = '0';
		else
			bin_num[i] = '1';
		dec /= 2;
		i--;
		limit--;
		if (dec == 0 && limit > 0)
			while (limit > 0 && i < size)
			{
				bin_num[i] = '0';
				limit--;
				i--;
			}
	}
}

unsigned int	bin_to_dec(int size, unsigned char *number,
		unsigned int array_size)
{
	unsigned int	result;
	int				i;

	i = 0;
	result = 0;
	while (i < array_size)
	{
		if (number[i] == '1')
			result += pow(2, ((size * 8) - i) - 1);
		i++;
	}
	return (result);
}
