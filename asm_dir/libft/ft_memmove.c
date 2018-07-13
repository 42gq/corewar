/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:35:38 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/26 15:08:30 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*dstp;
	const char	*srcp;

	srcp = src;
	dstp = dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	srcp += n;
	dstp += n;
	while (n--)
		*--dstp = *--srcp;
	return (dst);
}
