/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_incant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:26:29 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:26:31 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void			ft_action_incant(t_player *player, t_env *e)
{
	int			level;

	if (!strcmp(START_ELEV, player->read))
		printf("player %d : %s", player->num_player, START_ELEV);
	else if (!strncmp("niveau actuel : ", player->read, 16))
	{
		level = atoi(&player->read[16]);
		printf("level %d\n", level);
		player->level = level;
		player->cur_action = player->action[0];
		if (player->cur_action != NULL)
		{
			ft_destroy_action(player, 0);
			dprintf(player->sock, "%s", player->cur_action);
			printf("current : %s", player->cur_action);
		}
		e->graph.modif = 0;
	}
}
