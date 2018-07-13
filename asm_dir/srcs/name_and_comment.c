/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_and_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 01:48:35 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 03:10:25 by fdidelot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	stock_name(t_env *e, int i)
{
	int	j;

	j = 1;
	if (i > PROG_NAME_LENGTH + 1)
		return (0);
	if (!(e->name_player = (char *)ft_memalloc(sizeof(char) * i + 1)))
		ft_perror("malloc() failed.\n");
	while (j < i)
	{
		e->name_player[j - 1] = *(e->stock + e->count + j);
		j++;
	}
	e->name_player[j] = '\0';
	return (1);
}

int	name(t_env *e)
{
	int i;

	i = 0;
	e->count += skip_space(e->stock + e->count);
	if ((*(e->stock + e->count) == '.') &&
		ft_strncmp(e->stock + e->count, NAME_CMD_STRING, 5) == 0)
	{
		e->count += skip_space(e->stock + e->count + 5) + 5;
		if (*(e->stock + e->count) == '"')
		{
			i++;
			while (*(e->stock + e->count + i) != '"')
				i++;
			if (!stock_name(e, i))
				return (0);
			e->count += i;
		}
		else
			return (0);
	}
	else
		return (0);
	e->name_ok = 1;
	return (1);
}

int	stock_comment(t_env *e, int i)
{
	int	j;

	j = 1;
	if (i > COMMENT_LENGTH + 1)
		return (0);
	if (!(e->comment = (char *)ft_memalloc(sizeof(char) * i + 1)))
		ft_perror("malloc() failed.\n");
	while (j < i)
	{
		e->comment[j - 1] = *(e->stock + e->count + j);
		j++;
	}
	e->comment[j] = '\0';
	return (1);
}

int	comment(t_env *e)
{
	int i;

	i = 0;
	e->count += skip_space(e->stock + e->count);
	if ((*(e->stock + e->count) == '.') &&
		ft_strncmp(e->stock + e->count, COMMENT_CMD_STRING, 8) == 0)
	{
		e->count += skip_space(e->stock + e->count + 8) + 8;
		if (*(e->stock + e->count) == '"')
		{
			i++;
			while (*(e->stock + e->count + i) != '"')
				i++;
			if (!stock_comment(e, i))
				return (0);
			e->count += i;
		}
		else
			return (0);
	}
	else
		return (0);
	e->comment_ok = 1;
	return (1);
}
