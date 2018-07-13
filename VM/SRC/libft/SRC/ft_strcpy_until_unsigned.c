/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_until_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 07:15:03 by gquerre           #+#    #+#             */
/*   Updated: 2018/03/29 07:20:39 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strcpy_until_unsigned(unsigned char *dst,
		unsigned char *str, size_t i)
{
	size_t	k;

	k = 0;
	while (k < i)
	{
		dst[k] = str[k];
		k++;
	}
	dst[k] = '\0';
	return (dst);
}
