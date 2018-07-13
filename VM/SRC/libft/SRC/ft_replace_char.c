/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 04:32:43 by gquerre           #+#    #+#             */
/*   Updated: 2017/09/15 04:35:29 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_char(char *str, int i, char c)
{
	char	*add;

	add = ft_strdup(str);
	add[i] = c;
	return (add);
}
