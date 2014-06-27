/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   droite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 10:43:17 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/13 16:53:23 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	droite(t_env *e, t_clients *player)
{
	player->orient = modulo(player->orient + 1, 4);
	ft_strcat(player->buf_write, "ok\n");
	move_gfx(e, player);
	ft_memcpy(player->fct_action, player->fct_action + 1
		, sizeof(*player->fct_action) * player->i_action);
	ft_memcpy(player->action, player->action + 1
		, sizeof(*player->action) * player->i_action);
	ft_memcpy(player->arg, player->arg + 1
		, sizeof(*player->arg) * player->i_action);
	player->i_action--;
	(void)e;
}
