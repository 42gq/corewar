/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 18:24:02 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/26 15:26:27 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
		{
			return (tmp1[i] - tmp2[i]);
		}
		i++;
	}
	return (0);
}
