/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:08:35 by gquerre           #+#    #+#             */
/*   Updated: 2018/02/17 03:01:23 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	k;
	char	*mem;

	k = 0;
	if (!(s))
		return (NULL);
	if (!(mem = (char*)ft_memalloc((len + 1) * sizeof(char))))
		return (NULL);
	while (k != len)
		mem[k++] = s[start++];
	mem[k] = '\0';
	return (mem);
}
