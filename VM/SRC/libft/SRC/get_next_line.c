/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:56:29 by gquerre           #+#    #+#             */
/*   Updated: 2018/02/17 03:03:55 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./files.h/get_next_line.h"

char	*ft_put_line(char *mem)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = ft_strchr_count(mem, '\n');
	j = 0;
	new = ft_strnew(i);
	while (j < i)
	{
		new[j] = mem[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_clr_mem(char *str)
{
	size_t	i;
	char	*new;
	size_t	new_len;

	i = ft_strchr_count(str, '\n');
	new_len = (ft_strlen(str) - i);
	new = ft_strsub(str, i + 1, new_len);
	ft_strclr(str);
	free(str);
	return (new);
}

int		ft_control(int fd, char *buf, char **mem)
{
	int i;

	i = 0;
	while (!(ft_strchr(*mem, '\n')))
	{
		if ((i = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[i] = '\0';
		*mem = ft_strjoinfree(*mem, buf);
		ft_strclr(buf);
		if (i == 0)
		{
			if (ft_strlen(*mem) != 0)
				break ;
			return (0);
		}
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	static char	*mem;
	char		*buf;

	ret = 0;
	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (!(mem))
		if (!(mem = ft_strnew(1)))
			return (-1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = (ft_control(fd, buf, &mem));
	free(buf);
	if (ret < 1)
		return (ret);
	*line = ft_put_line(mem);
	mem = ft_clr_mem(mem);
	return (1);
}
