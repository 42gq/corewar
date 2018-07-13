/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_1stcharbool.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 04:32:52 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/15 04:32:55 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_1stcharbool(char *str, int i, char c, char d)
{
	char	*add;

	add = NULL;
	add = ft_strnew(1);
	add[0] = (i) ? c : d;
	add = ft_strjoin(add, str);
	return (add);
}
