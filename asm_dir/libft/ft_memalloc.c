/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:36:01 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/28 14:51:54 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	char	*tmp;

	if (size < 1)
		return (NULL);
	mem = (void*)malloc(size);
	tmp = (char*)mem;
	if (mem)
	{
		while (size > 0)
		{
			*tmp++ = 0;
			size--;
		}
	}
	else
		return (NULL);
	return (mem);
}
