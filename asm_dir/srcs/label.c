/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdidelot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 02:42:03 by fdidelot          #+#    #+#             */
/*   Updated: 2018/05/02 06:18:11 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		skip_label(t_env *e, int sl)
{
	int	i;

	i = 0;
	while (i < sl && e->stock[e->count + i] != COMMENT_CHAR)
	{
		if (e->stock[e->count + i] == LABEL_CHAR)
		{
			if (ft_isprint(e->stock[e->count + i - 1]) &&
				e->stock[e->count + i - 1] != DIRECT_CHAR)
				return (i + 1);
		}
		i++;
	}
	return (0);
}

void	create_label_lst(t_env *e, int start, int end)
{
	t_label *tmp;

	if (e->lst_label == NULL)
	{
		if (!(e->lst_label = (t_label *)ft_memalloc(sizeof(t_label))))
			ft_perror("malloc() failed.\n");
		tmp = e->lst_label;
	}
	else
	{
		tmp = e->lst_label;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->next == NULL)
		{
			if (!(tmp->next = (t_label *)ft_memalloc(sizeof(t_label))))
				ft_perror("malloc() failed.\n");
			tmp = tmp->next;
		}
	}
	tmp->placement = e->size_player;
	if (!(tmp->name = (char *)ft_memalloc(sizeof(char) * (end - start + 2))))
		ft_perror("malloc() failed.\n");
	ft_strncpy(tmp->name, e->stock + e->count + start, end - start + 1);
	tmp->next = NULL;
}

void	supa_strukt(t_env *e, t_label *tmp, t_pukutak puku)
{
	tmp->placement = e->size_player;
	tmp->deca = puku.deca;
	tmp->dir_size = puku.size_dir;
}

void	create_label_stock(t_env *e, int start, int end, t_pukutak puku)
{
	t_label *tmp;

	if (e->stock_label == NULL)
	{
		if (!(e->stock_label = (t_label *)ft_memalloc(sizeof(t_label))))
			ft_perror("malloc() failed.\n");
		tmp = e->stock_label;
	}
	else
	{
		tmp = e->stock_label;
		while (tmp->next)
			tmp = tmp->next;
		if (tmp->next == NULL)
		{
			if (!(tmp->next = (t_label *)ft_memalloc(sizeof(t_label))))
				ft_perror("malloc() failed.\n");
			tmp = tmp->next;
		}
	}
	supa_strukt(e, tmp, puku);
	if (!(tmp->name = (char *)ft_memalloc(sizeof(char) * (end - start + 2))))
		ft_perror("malloc() failed.\n");
	ft_strncpy(tmp->name, e->stock + e->count + start, end - start + 1);
	tmp->next = NULL;
}

void	get_label(t_env *e, int start, int deca, int dir_size)
{
	int			end;
	int			size_dir;
	t_pukutak	puku;

	size_dir = 2;
	if (dir_size == 0)
		size_dir = 4;
	end = start;
	puku.size_dir = size_dir;
	puku.deca = deca;
	while (ft_isprint(e->stock[e->count + end]) &&
		e->stock[e->count + end] != SEPARATOR_CHAR)
		end++;
	create_label_stock(e, start + 1, end - 1, puku);
}
