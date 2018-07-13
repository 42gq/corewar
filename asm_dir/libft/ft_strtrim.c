/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 19:15:21 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/26 18:29:42 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	size_t	length;
	size_t	end;
	size_t	start;
	char	*dst;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = 0;
	length = ft_strlen(s);
	while (ft_iswhitespace(s[start]))
		start++;
	while (ft_iswhitespace(s[length - end - 1]))
		end++;
	if (start == length)
		end = 0;
	if (!(dst = ft_strnew(length)))
		return (NULL);
	dst = ft_strncpy(dst, s + start, length - start - end);
	dst[length - start - end] = '\0';
	return (dst);
}
