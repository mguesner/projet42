/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_droite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:25:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:25:59 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void			ft_action_droite(t_player *player, t_env *e)
{
	if (!strcmp(player->read, OK))
	{
		printf("succes %s\n", player->cur_action);
		ft_change_view(player, e);
		if (player->view < 3)
			player->view++;
		else
			player->view = 0;
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
