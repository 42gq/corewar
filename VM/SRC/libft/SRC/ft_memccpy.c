/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmemccpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:58:35 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/09 21:44:43 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*srcchar;
	char	*dstt;

	dstt = (char *)(dst);
	srcchar = (char *)(src);
	i = 0;
	while (i < n)
	{
		if ((*dstt++ = *srcchar++) == (char)c)
			return (dstt);
		i++;
	}
	return (0);
}
