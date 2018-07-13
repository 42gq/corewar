/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 08:52:40 by gquerre           #+#    #+#             */
/*   Updated: 2016/12/18 06:55:20 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)(&(s[i])));
	while ((char)(s[i]) != (char)c && i > 0)
		i--;
	if ((char)(s[i]) == (char)c)
		return ((char *)(&(s[i])));
	return (NULL);
}
