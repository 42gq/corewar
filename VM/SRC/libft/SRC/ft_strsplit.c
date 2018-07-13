/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 01:14:02 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/09 18:19:04 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_w_count(char *s, char c)
{
	int i;
	int k;

	k = 0;
	i = 0;
	if (!(s))
		return (0);
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			k++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		k++;
	return (k);
}

static int		f(char *s, char c, int j)
{
	int i;
	int k;
	int r;

	k = 0;
	i = 0;
	r = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		while (s[i] != c && k != j && s[i] != '\0')
			i++;
		while (s[i] != c && k == j && s[i++] != '\0')
			r++;
		if (s[i] == c)
		{
			k++;
			while (s[i] == c)
				i++;
		}
	}
	return (r + 1);
}

char			**ft_strsplit2(char const *s, char c, char **tab)
{
	int	i;
	int	k;
	int	j;

	i = -1;
	k = 0;
	j = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			if (!(tab[j] = (char*)malloc(sizeof(char) * f((char *)s, c, j))))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				tab[j][k++] = s[i++];
			tab[j][k] = '\0';
			k = 0;
			j++;
			i--;
		}
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!(s))
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_w_count((char *)s, c) + 1))))
		return (NULL);
	return (ft_strsplit2(s, c, tab));
}
