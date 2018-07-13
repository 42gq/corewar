/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 18:23:46 by fdidelot          #+#    #+#             */
/*   Updated: 2017/03/15 05:01:56 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub_free(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	free((void *)s);
	return (dst);
}
