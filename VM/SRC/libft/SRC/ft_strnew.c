/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:08:37 by gquerre           #+#    #+#             */
/*   Updated: 2017/07/24 05:05:51 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*mem;

	i = 0;
	if (!(mem = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (i != size)
		mem[i++] = '\0';
	mem[i] = '\0';
	return (mem);
}
