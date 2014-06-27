/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_human.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:19:40 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:19:43 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void			ft_destroy_action(t_player *player, int i)
{
	while (i < (MAX_ACTION - 1))
	{
		player->action[i] = player->action[i + 1];
		i++;
	}
	player->action[i] = NULL;
	player->nb_action--;
}

static void		st_check_action(t_player *player)
{
	pthread_mutex_lock(&player->mutex);
	if (!player->cur_action && player->status == 4)
	{
		player->cur_action = player->action[0];
		if (player->cur_action)
		{
			if (dprintf(player->sock, "%s", player->cur_action) == -1)
				printf("error write action human\n");
			printf("envoie commande : %s\n", player->cur_action);
			ft_destroy_action(player, 0);
		}
	}
	pthread_mutex_unlock(&player->mutex);
}

void			ft_check_action(t_env *e)
{
	int			i;

	i = 0;
	FD_ZERO(&e->fd_read);
	while (i < MAX_PLAYER)
	{
		if (e->players[i].type == FD_PLAYER)
		{
			st_check_action(&e->players[i]);
			FD_SET(e->players[i].sock, &e->fd_read);
			if (e->max_fd < e->players[i].sock)
				e->max_fd = e->players[i].sock;
		}
		i++;
	}
}
