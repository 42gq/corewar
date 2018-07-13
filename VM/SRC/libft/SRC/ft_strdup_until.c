/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 06:04:46 by gquerre           #+#    #+#             */
/*   Updated: 2017/07/03 08:51:37 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_until(const char *s1, int i)
{
	char *s2;

	if (!(s2 = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (0);
	s2 = ft_strcpy_until((char *)s1, i);
	return (s2);
}
