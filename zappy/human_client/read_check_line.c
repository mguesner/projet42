/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:27:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:27:59 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void	st_check_cmd(t_player *player, t_env *e)
{
	if (!strcmp(player->cur_action, AVANCE))
		ft_action_avance(player, e);
	else if (!strcmp(player->cur_action, DROITE))
		ft_action_droite(player, e);
	else if (!strcmp(player->cur_action, GAUCHE))
		ft_action_gauche(player, e);
	else if (!strcmp(player->cur_action, VOIR))
		ft_action_voir(player, e);
	else if (!strcmp(player->cur_action, INVENTAIRE))
		ft_action_inventaire(player, e);
	else if (!strcmp(player->cur_action, FORK))
		ft_action_fork(player, e);
	else if (!strcmp(player->cur_action, INCANT))
		ft_action_incant(player, e);
	else if (!strncmp(player->cur_action, "prend ", 6))
		ft_action_prendre(player, e);
	else if (!strncmp(player->cur_action, "pose ", 5))
		ft_action_poser(player, e);
}

static void	st_check_status_ok(t_player *player, t_env *e)
{
	int		i;

	if (!strncmp("mort", player->read, 4))
	{
		i = player->num_player;
		ft_destroy_player(e, player->num_player - 1);
		e->cur_player = &e->players[i];
		if (e->cur_player->type == FD_FREE)
			printf("all player is died");
		e->graph.modif = 0;
	}
	else if (!strncmp("broadcast ", player->read, 10))
		;
	else if (player->cur_action)
		st_check_cmd(player, e);
	else if (!strncmp("niveau actuel : ", player->read, 16))
	{
		player->level = atoi(&player->read[16]);
		printf("level %d\n", player->level);
	}
}

static void	st_check_status_other(t_player *player, t_env *e)
{
	if (!strcmp(player->read, BIENVENUE) && player->status == 1)
	{
		printf("%s\n", player->read);
		dprintf(player->sock, "%s %s\n", INTER, e->team);
		player->status = 2;
	}
	else if (player->status == 2)
	{
		printf("%s\n", player->read);
		player->status = 3;
	}
	else if (player->status == 3)
	{
		if (!e->map)
			ft_check_coor(e, player);
		player->status = 4;
	}
	else if (player->status == 4)
	{
		player->view = atoi(player->read);
		player->status = 5;
		printf("num player ok%d\n", player->num_player);
	}
}

void		ft_check_line(t_player *player, t_env *e)
{
	pthread_mutex_lock(&e->mutex);
	if (player->status == 5)
		st_check_status_ok(player, e);
	else
		st_check_status_other(player, e);
	pthread_mutex_unlock(&e->mutex);
}
