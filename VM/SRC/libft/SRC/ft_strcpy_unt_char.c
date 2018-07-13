/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_unt_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 04:18:25 by gquerre           #+#    #+#             */
/*   Updated: 2018/01/16 05:57:57 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_unt_char(char *src, char c)
{
	size_t	k;
	size_t	i;
	char	*dst;

	i = 0;
	k = 0;
	while (src[i] && src[i] != c)
		i++;
	if (!(dst = ft_memalloc(sizeof(char) * i + 1)))
		return (NULL);
	while (src[k] && k < i)
	{
		dst[k] = src[k];
		k++;
	}
	dst[k] = '\0';
	return (dst);
}
