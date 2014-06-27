/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 13:41:20 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 14:33:41 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

void	next_action(t_clients *player)
{
	memcpy(player->fct_action, player->fct_action + 1
		, sizeof(*player->fct_action) * player->i_action);
	memcpy(player->action, player->action + 1
		, sizeof(*player->action) * player->i_action);
	memcpy(player->arg, player->arg + 1
		, sizeof(*player->arg) * player->i_action);
	player->i_action--;
	if (player->action[player->i_action] == 300)
		strcat(player->buf_write, "elevation en cours\n");
}
