/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 01:04:40 by gquerre           #+#    #+#             */
/*   Updated: 2018/05/02 08:22:11 by snedir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

off_t	ft_save_name(t_env *e, int i, int fd)
{
	unsigned char	magic_nb[4];
	unsigned char	*buff;
	int				k;

	magic_nb[0] = 0;
	magic_nb[1] = 234;
	magic_nb[2] = 131;
	magic_nb[3] = 243;
	k = -1;
	if (!(buff = ft_memalloc(sizeof(char) * 4)))
		return (0);
	if ((read(fd, buff, 4)) == -1)
		return (0);
	while (++k < 4)
		if (buff[k] != magic_nb[k])
		{
			free(buff);
			return (0);
		}
	free(buff);
	if (!(e->players[i].name = ft_memalloc(sizeof(char) * (NAME_SIZE + 1))))
		return (0);
	if (read(fd, e->players[i].name, NAME_SIZE) == -1)
		return (0);
	return (NAME_SIZE + 8);
}

off_t	ft_save_comment(t_env *e, int i, int fd, off_t pos)
{
	unsigned char	tmp[5];

	tmp[4] = '\0';
	if ((lseek(fd, pos, SEEK_SET) == -1))
		return (0);
	if (read(fd, tmp, 4) == -1)
		return (0);
	if ((tmp[0] != 0) || (tmp[1] != 0) ||
				(e->players[i].size = tmp[2] * 256 + tmp[3]) > CHAMP_MAX_SIZE)
		return (0);
	if (!(e->players[i].comment =
				ft_memalloc(sizeof(char) * (COMMENT_SIZE + 1))))
		return (0);
	if (read(fd, e->players[i].comment, COMMENT_SIZE) == -1)
		return (0);
	return (NAME_SIZE + COMMENT_SIZE + 16);
}

off_t	ft_put_champ_in_arena(t_env *e, int i, int fd, off_t pos)
{
	off_t			end;
	int				place_in_arena;
	unsigned char	*buff;
	int				a;

	place_in_arena = (MEM_SIZE * i / e->nb_of_pl);
	a = place_in_arena - 1;
	end = 0;
	buff = NULL;
	if (lseek(fd, pos, SEEK_SET) == -1)
		return (0);
	if (!(buff = ft_memalloc(sizeof(char) * (e->players[i].size + 1))))
		return (0);
	if (read(fd, buff, e->players[i].size) == -1)
		return (0);
	while (++a < e->players[i].size + place_in_arena)
		e->written_by[a] = i + 1;
	if (ft_strcpy_until_unsigned(&e->arena[place_in_arena],
				buff, e->players[i].size) == NULL)
	{
		free(buff);
		return (0);
	}
	free(buff);
	return (1);
}

int		ft_import_champ(t_env *e, int i, char *argv)
{
	int			fd;
	off_t		pos;

	fd = 0;
	pos = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	if (!(pos = ft_save_name(e, i, fd)))
		return (0);
	if (!(pos = ft_save_comment(e, i, fd, pos)))
		return (0);
	if (!(e->players[i].size))
		return (0);
	if (!(ft_put_champ_in_arena(e, i, fd, pos)))
		return (0);
	close(fd);
	return (1);
}

int		ft_init_player(t_env *e, char *argv)
{
	static int	i = 0;
	static int	k = 0;

	if (e->forced_nb_for_pl)
	{
		e->players[i].num_player = e->forced_nb_for_pl;
		e->forced_nb_for_pl = 0;
		k++;
	}
	else
		e->players[i].num_player = -(i + 1 - k);
	e->players[i].id = (unsigned int)e->players[i].num_player;
	e->players[i].lives_periode = 0;
	e->players[i].total_lives = 0;
	e->players[i].last_live = 0;
	e->players[i].size = 0;
	e->players[i].very_last_flag = 0;
	if (!(ft_import_champ(e, i, argv)))
		return (0);
	i++;
	return (1);
}
