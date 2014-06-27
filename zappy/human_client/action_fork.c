/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:26:06 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:26:07 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void		ft_action_fork(t_player *player, t_env *e)
{
	printf("%s\n", FORK);
	if (!strcmp(player->read, OK))
	{
		e->egg[e->egg_use].t = time(NULL);
		e->egg[e->egg_use].status = EGG_PONDU;
		ft_add_player(&e->players[e->nb_player], player->y, player->x);
		player->cur_action = player->action[0];
		if (player->cur_action != NULL)
		{
			ft_destroy_action(player, 0);
			dprintf(player->sock, "%s", player->cur_action);
			printf("current : %s", player->cur_action);
		}
		e->graph.modif = 0;
		e->egg_use++;
		e->connect++;
	}
}
