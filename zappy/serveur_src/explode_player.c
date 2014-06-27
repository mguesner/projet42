/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explode_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 11:16:54 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 14:29:06 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdlib.h>

static void	explode_player2(t_env *e, t_clients *player)
{
	int		x;
	int		y;

	while (player->mendiane > 0 && player->mendiane--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].mendiane++;
		contenue2(e, y, x);
	}
	while (player->phiras > 0 && player->phiras--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].phiras++;
		contenue2(e, y, x);
	}
	while (player->thystame > 0 && player->thystame--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].thystame++;
		contenue2(e, y, x);
	}
}

void		explode_player(t_env *e, t_clients *player)
{
	int		x;
	int		y;

	while (player->linemate > 0 && player->linemate--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].linemate++;
		contenue2(e, y, x);
	}
	while (player->deraumere > 0 && player->deraumere--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].deraumere++;
		contenue2(e, y, x);
	}
	while (player->sibur > 0 && player->sibur--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].sibur++;
		contenue2(e, y, x);
	}
	explode_player2(e, player);
}
