/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:53:36 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/26 18:07:55 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t length_d;
	size_t length_s;

	length_d = ft_strlen(dst);
	length_s = ft_strlen(src);
	if (length_d < size)
	{
		dst = ft_strncat(dst, src, size - length_d - 1);
		return (length_s + length_d);
	}
	return (length_s + size);
}
