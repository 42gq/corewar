/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 05:22:30 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/09 22:32:43 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strtrim_count(char *s)
{
	size_t		spaces;
	size_t		i;
	size_t		len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	spaces = i;
	if (s[i] != '\0')
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			spaces++;
			i--;
		}
	}
	return (len - spaces);
}

char			*ft_strtrim(char const *s)
{
	char		*mem;
	int			i;
	size_t		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	mem = ft_strnew(ft_strtrim_count((char *)s));
	if (mem == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (k < ft_strtrim_count((char *)s))
	{
		mem[k] = s[i];
		i++;
		k++;
	}
	return (mem);
}
