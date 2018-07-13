/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 16:42:54 by fdidelot          #+#    #+#             */
/*   Updated: 2014/11/28 15:05:45 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nb_word(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			nb++;
			i++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (nb);
}

static char		*add_word(size_t *i, char const *s, char c)
{
	size_t	size;
	size_t	j;
	char	*word;

	size = *i;
	j = 0;
	while (s[size] && s[size] != c)
		size++;
	word = ft_strnew(size - *i);
	if (word)
	{
		while (*i < size)
		{
			word[j] = s[*i];
			j++;
			*i += 1;
		}
		return (word);
	}
	return (0);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	size_t	o;
	size_t	*i;
	size_t	j;

	o = 0;
	i = &o;
	j = 0;
	tab = NULL;
	if (s)
		tab = (char**)malloc(sizeof(char*) * (ft_nb_word(s, c) + 1));
	if (tab)
	{
		while (j < ft_nb_word(s, c))
		{
			while (s[*i] == c)
				*i += 1;
			if (s[*i] != c && s[*i])
				tab[j++] = add_word(i, s, c);
		}
		tab[j] = 0;
		return (tab);
	}
	return (0);
}
