/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 03:20:37 by gquerre           #+#    #+#             */
/*   Updated: 2016/12/18 05:20:32 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mem;

	if (!(s))
		return (NULL);
	i = -1;
	if (!(mem = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[++i] != '\0')
		mem[i] = f(i, s[i]);
	mem[i] = '\0';
	return (mem);
}
