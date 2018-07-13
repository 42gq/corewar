/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 05:14:19 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/28 06:27:29 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	int		i;
	int		k;
	int		u;

	mem = NULL;
	i = 0;
	k = 0;
	u = ft_strlen(s1) + ft_strlen(s2);
	if (!(mem = (char*)ft_memalloc(sizeof(char) * u + 1)))
		return (NULL);
	while (s1 && s1[0] && s1[i] != '\0')
	{
		mem[i] = s1[i];
		i++;
	}
	while (i + k < u && s2[k])
	{
		mem[i + k] = s2[k];
		k++;
	}
	mem[i + k] = '\0';
	return (mem);
}
