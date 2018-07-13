/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkedge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 18:00:26 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/09 20:44:48 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkedge(char **str)
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
	if ((size_t)i != nb)
		return (0);
	return (i);
}
