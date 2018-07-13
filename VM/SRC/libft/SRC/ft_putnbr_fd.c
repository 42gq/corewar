/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:34:06 by gquerre           #+#    #+#             */
/*   Updated: 2017/01/09 21:22:04 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	i = (unsigned int)n;
	if (i >= 10)
	{
		ft_putnbr_fd((i / 10), fd);
		ft_putnbr_fd((i % 10), fd);
	}
	else if (i <= 9)
		ft_putchar_fd(i + '0', fd);
}
