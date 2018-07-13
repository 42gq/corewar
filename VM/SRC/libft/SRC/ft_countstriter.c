/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstriter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:11:30 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/07 19:03:07 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countstriter(char *str, char *iter)
{
	int i;
	int k;
	int j;

	j = 0;
	i = -1;
	k = 0;
	if (!(str) || !(iter))
		return (0);
	while (str[++i] != '\0')
	{
		while (iter[j] == str[i + j] && iter[j] != '\0')
			j++;
		if (iter[j] == '\0')
			k++;
		j = 0;
	}
	return (k);
}
