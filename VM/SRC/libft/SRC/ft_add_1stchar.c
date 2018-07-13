/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_1stchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 03:28:01 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/06 02:12:02 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_1stchar(char *str, char c)
{
	char	*add;
	char	*res;

	add = NULL;
	res = NULL;
	if (!(add = ft_strnew(1)))
		return (NULL);
	add[0] = c;
	res = ft_strjoinfree_both(add, str);
	return (res);
}
