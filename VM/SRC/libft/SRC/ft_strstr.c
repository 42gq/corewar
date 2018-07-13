/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 05:46:53 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/07 15:32:46 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int k;

	if (!(little[0]))
		return ((char *)(big));
	i = 0;
	k = 0;
	while (big[i + k] != '\0' && little[i] != '\0')
	{
		while (little[i] != big[i + k])
		{
			if (big[i + k] == '\0')
				return (NULL);
			k++;
		}
		while (little[i] == big[i + k] && big[i + k] != '\0')
			i++;
		if (little[i] == '\0')
			return ((char *)(&big[k]));
		i = 0;
		k++;
	}
	return (NULL);
}
