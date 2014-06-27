/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_player_human.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:20:48 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:20:51 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void			ft_add_player(t_player *player, int y, int x)
{
	player->y = y;
	player->x = x;
}

int				ft_init_player(t_env *e, int i)
{
	int			j;

	j = 0;
	e->players[i].type = FD_FREE;
	e->players[i].cur_action = NULL;
	while (j < MAX_ACTION)
		e->players[i].action[j++] = NULL;
	e->players[i].nb_action = 0;
	e->players[i].num_player = i + 1;
	bzero(e->players[i].read, BUFF_H);
	e->players[i].ret_read = 0;
	e->players[i].status = 0;
	e->players[i].y = -1;
	e->players[i].x = -1;
	e->players[i].view = 0;
	e->players[i].level = 0;
	pthread_mutex_init(&e->players[i].mutex, NULL);
	e->players[i].start_action = 0;
	ft_init_inventaire(&e->players[i]);
	return (0);
}

static void		st_player(t_case *place, int num)
{
	place->my_player = num;
}

static void		st_deplace_player(t_env *e, int i)
{
	while (i < (MAX_PLAYER - 1))
	{
		e->players[i] = e->players[i + 1];
		if (e->players[i].y >= 0 && e->players[i].x >= 0)
			st_player(&e->map[e->players[i].y][e->players[i].x],
						e->players[i].num_player);
		i++;
		e->players[i].num_player = i + 1;
	}
}

void			ft_destroy_player(t_env *e, int i)
{
	t_player	*tmp;
	int			j;

	tmp = &e->players[i];
	ft_change_view(tmp, e);
	if (tmp->y >= 0 && tmp->x >= 0)
		e->map[tmp->y][tmp->x].my_player = 0;
	tmp->type = FD_FREE;
	tmp->cur_action = NULL;
	close(tmp->sock);
	j = 0;
	while (j < MAX_ACTION)
		tmp->action[j++] = NULL;
	tmp->status = 0;
	tmp->nb_action = 0;
	tmp->num_player = 10;
	tmp->y = -1;
	tmp->x = -1;
	e->players[i].view = 0;
	e->players[i].level = 0;
	st_deplace_player(e, i);
	e->players[MAX_PLAYER - 1] = *tmp;
	e->nb_player--;
}
