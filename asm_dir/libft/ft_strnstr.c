/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 18:06:10 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/20 17:48:01 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s2);
	if (size == 0)
		return ((char*)s1);
	while (s1[i] && n-- >= size)
	{
		if (s1[i] == s2[0] && ft_strncmp((const char*)(s1 + i), s2, size) == 0)
			return ((char*)(s1 + i));
		i++;
	}
	return (NULL);
}
