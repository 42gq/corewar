/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 09:07:24 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/07 15:32:18 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = ft_strlen(little);
	if (!(little) || (little[0] == '\0'))
		return ((char *)(big));
	while (big[i] && i < n)
	{
		while (little[j] == big[i + j] && (i + j) < n && big[j] != '\0')
		{
			if (j == size - 1 || little[j] == '\0')
				return ((char *)(&big[i]));
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
