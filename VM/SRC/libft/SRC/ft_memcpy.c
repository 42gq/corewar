/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:10:38 by gquerre           #+#    #+#             */
/*   Updated: 2016/12/18 02:28:41 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*srcc;
	char	*dstt;

	srcc = (char *)(src);
	dstt = (char *)(dst);
	i = 0;
	while (i < n)
	{
		dstt[i] = srcc[i];
		i++;
	}
	return (dst);
}
