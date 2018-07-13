/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:03:12 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/20 16:12:14 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)dst;
	s2 = (char*)src;
	while (n > 0)
	{
		*s1 = *s2;
		if (*s1 == c)
			return (s1 + 1);
		s1++;
		s2++;
		n--;
	}
	return (NULL);
}
