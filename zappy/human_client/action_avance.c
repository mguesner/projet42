/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_avance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:25:37 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:25:46 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void			ft_action_avance(t_player *player, t_env *e)
{
	printf("%s\n", AVANCE);
	if (!strcmp(player->read, OK))
	{
		printf("succes %s\n", player->cur_action);
		if (player->view == VIEW_NORTH)
			ft_change_case(player, e, player->y - 1, player->x);
		else if (player->view == VIEW_EAST)
			ft_change_case(player, e, player->y, player->x + 1);
		else if (player->view == VIEW_SOUTH)
			ft_change_case(player, e, player->y + 1, player->x);
		else
			ft_change_case(player, e, player->y, player->x - 1);
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
