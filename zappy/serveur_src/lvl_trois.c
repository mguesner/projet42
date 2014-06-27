/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lvl_trois.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 14:09:07 by nguezell          #+#    #+#             */
/*   Updated: 2014/06/23 15:15:50 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		lvl_trois(t_env *e, t_clients *player, t_case autel)
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
	if (nb >= 2 && autel.linemate >= 2 && autel.sibur >= 1 && autel.phiras >= 2)
	{
		i = -1;
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
