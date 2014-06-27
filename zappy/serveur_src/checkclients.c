/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkclients.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 16:06:49 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 13:55:58 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdio.h>
#include <libft.h>

void	checkclients(t_env *e, unsigned long t, unsigned long last_t)
{
	int		i;

	i = -1;
	while (++i <= e->max_fd)
	{
		if (FD_ISSET(i, &e->fd_read))
			e->clients[i].fct_read(e, i);
		if ((TYPE(i) == CLIENT_CLIENT || TYPE(i) == CLIENT_ATT)
			&& e->clients[i].start != e->clients[i].end)
			e->clients[i].fct_cmd(e, i);
		if (e->clients[i].type == CLIENT_CLIENT
			&& e->clients[i].connected && t - last_t
			>= (unsigned long)((1. / e->time) * 1000000))
		{
			if (e->clients[i].action[0] > 0 && --e->clients[i].action[0] == 0)
				e->clients[i].fct_action[0](e, &e->clients[i]);
			eat(e, &e->clients[i]);
		}
		if (!FD_ISSET(i, &e->fd_read) && FD_ISSET(i, &e->fd_write))
			e->clients[i].fct_write(e, i);
		if (FD_ISSET(i, &e->fd_read) || FD_ISSET(i, &e->fd_write))
			e->ret--;
	}
	if (t - last_t >= (unsigned long)((1. / e->time) * 1000000))
		checkoeuf(e);
}
