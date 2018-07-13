/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 03:40:24 by gquerre           #+#    #+#             */
/*   Updated: 2018/01/16 01:20:36 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp_until(char *s1, char *s2, int lim)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i <= lim)
		i++;
	if (i == lim)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
