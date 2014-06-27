/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventaire.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:30:36 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/13 16:40:12 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <stdio.h>

void	inventaire(t_env *e, t_clients *player)
{
	char	cmd[BUF_SIZE];

	sprintf(cmd, "nourriture %d, linemate %d, deraumere %d, sibur %d,"
		, player->life / 126, player->linemate, player->deraumere
		, player->sibur);
	sprintf(cmd + strlen(cmd), " mendiane %d, phiras %d, thystame %d\n"
		, player->mendiane, player->phiras, player->thystame);
	ft_strcat(player->buf_write, cmd);
	ft_memcpy(player->fct_action, player->fct_action + 1
		, sizeof(*player->fct_action) * player->i_action);
	ft_memcpy(player->action, player->action + 1,
		sizeof(*player->action) * player->i_action);
	ft_memcpy(player->arg, player->arg + 1
		, sizeof(*player->arg) * player->i_action);
	player->i_action--;
	(void)e;
}
