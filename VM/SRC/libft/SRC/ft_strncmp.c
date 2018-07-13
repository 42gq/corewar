/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:16:42 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/09 21:10:04 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!n)
		return (0);
	while ((((char *)s1)[i]) == (((char *)s2)[i])
			&& (((char *)s1)[i]) != '\0' && i < n - 1)
		i++;
	return (int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
