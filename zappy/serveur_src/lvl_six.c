/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_six.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 14:09:39 by nguezell          #+#    #+#             */
/*   Updated: 2014/06/23 15:14:08 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		lvl_six(t_env *e, t_clients *player, t_case autel)
{
	int		nb;
	int		i;

	nb = 0;
	i = -1;
	while (++i <= e->max_fd)
		if (e->clients[i].type == CLIENT_CLIENT
			&& e->clients[i].X == player->X
			&& e->clients[i].Y == player->Y
			&& e->clients[i].lvl == player->lvl)
			nb++;
	if (nb >= 6 && autel.linemate >= 1 && autel.deraumere >= 2
		&& autel.sibur >= 3 && autel.mendiane >= 0 && autel.phiras >= 1
		&& autel.thystame >= 0 && (i = -1))
	{
		player->lvl++;
		while (++i <= e->max_fd)
			if (e->clients[i].type == CLIENT_CLIENT
				&& e->clients[i].X == player->X
				&& e->clients[i].Y == player->Y
				&& e->clients[i].lvl == player->lvl - 1)
				e->clients[i].lvl++;
		return (1);
	}
	return (0);
}
