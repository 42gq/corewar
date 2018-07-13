/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_text_kbhit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 06:59:09 by gquerre           #+#    #+#             */
/*   Updated: 2018/04/10 09:10:40 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar_vm.h"

int	unix_text_kbhit(void)
{
	struct timeval	tv;
	fd_set			readfds;

	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&readfds);
	FD_SET(STDIN_FILENO, &readfds);
	return (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1);
}
