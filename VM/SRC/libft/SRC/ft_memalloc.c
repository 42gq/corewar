/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 21:51:01 by gquerre           #+#    #+#             */
/*   Updated: 2017/07/31 03:10:10 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	i = -1;
	if (size == 0)
		return (NULL);
	if (!(mem = malloc(size * sizeof(*mem))))
		return (NULL);
	while (++i != size)
		mem[i] = '\0';
	return ((void *)(mem));
}
