/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avance.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 10:15:45 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/19 15:52:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	avance(t_env *e, t_clients *player)
{
	(e->map[player->Y][player->X].joueur)--;
	if (player->orient == 1)
		player->X = modulo(player->X + 1, e->width);
	if (player->orient == 2)
		player->Y = modulo(player->Y + 1, e->height);
	if (player->orient == 3)
		player->X = modulo(player->X - 1, e->width);
	if (player->orient == 0)
		player->Y = modulo(player->Y - 1, e->height);
	(e->map[player->Y][player->X].joueur)++;
	strcat(player->buf_write, "ok\n");
	memcpy(player->fct_action, player->fct_action + 1
		, sizeof(*player->fct_action) * player->i_action);
	memcpy(player->action, player->action + 1
		, sizeof(*player->action) * player->i_action);
	memcpy(player->arg, player->arg + 1
		, sizeof(*player->arg) * player->i_action);
	(player->i_action)--;
	move_gfx(e, player);
}
