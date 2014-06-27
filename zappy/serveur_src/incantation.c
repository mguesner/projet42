/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incantation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:14:38 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 14:41:01 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <stdio.h>

static int	incantation2(t_env *e, t_clients *player)
{
	if (player->lvl == 1)
		return (lvl_un(e, player, e->map[player->Y][player->X]));
	else if (player->lvl == 2)
		return (lvl_deux(e, player, e->map[player->Y][player->X]));
	else if (player->lvl == 3)
		return (lvl_trois(e, player, e->map[player->Y][player->X]));
	else if (player->lvl == 4)
		return (lvl_quatre(e, player, e->map[player->Y][player->X]));
	else if (player->lvl == 5)
		return (lvl_cinq(e, player, e->map[player->Y][player->X]));
	else if (player->lvl == 6)
		return (lvl_six(e, player, e->map[player->Y][player->X]));
	else if (player->lvl == 7)
		return (lvl_sept(e, player, e->map[player->Y][player->X]));
	return (0);
}

void		incantation(t_env *e, t_clients *player)
{
	int		i;
	int		lvl_up;
	char	tmp[BUF_SIZE];

	lvl_up = incantation2(e, player);
	i = -1;
	while (++i <= e->max_fd)
	{
		if (e->clients[i].type == CLIENT_CLIENT && e->clients[i]
.X == player->X && e->clients[i].Y == player->Y)
		{
			sprintf(e->clients[i].buf_write + strlen(e->clients[i].buf_write)
				, "niveau actuel : %d\n", e->clients[i].lvl);
			sprintf(tmp, "lvl %d %d %s\n", e->clients[i].nb
				, e->clients[i].lvl, e->clients[i].name);
			maj_gfx(e, tmp);
		}
	}
	if (lvl_up == 1)
		explode_case(e, &e->map[player->Y][player->X]);
	else if (lvl_up == 8)
		end_game(e, player);
	next_action(player);
}
