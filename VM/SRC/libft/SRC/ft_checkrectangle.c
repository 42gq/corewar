/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkrectangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:50:01 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/09 20:45:06 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkrectangle(char **str)
{
	int		i;
	size_t	nb;

	i = 0;
	nb = ft_strlen(str[i]);
	i++;
	while (str[i] != '\0')
	{
		if (ft_strlen(str[i]) != nb)
			return (0);
		i++;
	}
	return (i);
}
