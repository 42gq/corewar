/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:49:58 by fdidelot          #+#    #+#             */
/*   Updated: 2016/12/22 17:26:23 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *m, int n, size_t s)
{
	unsigned char	*tmp;

	if (s == 0)
		return (m);
	tmp = (unsigned char*)m;
	while (s--)
	{
		*tmp = (unsigned char)n;
		tmp++;
	}
	return (m);
}
