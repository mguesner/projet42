/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_poser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:26:51 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:26:52 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void			ft_check_action_poser(t_env *e, int keycode)
{
	if (keycode == 49)
		ft_check_action_mlx(e->cur_player, POSER_L, e);
	else if (keycode == 50)
		ft_check_action_mlx(e->cur_player, POSER_D, e);
	else if (keycode == 51)
		ft_check_action_mlx(e->cur_player, POSER_S, e);
	else if (keycode == 52)
		ft_check_action_mlx(e->cur_player, POSER_M, e);
	else if (keycode == 53)
		ft_check_action_mlx(e->cur_player, POSER_P, e);
	else if (keycode == 54)
		ft_check_action_mlx(e->cur_player, POSER_T, e);
	else if (keycode == 55)
		ft_check_action_mlx(e->cur_player, POSER_FOOD, e);
}

static void		st_action_poser(t_player *player, t_env *e,
									unsigned char *obj, int *o)
{
	printf("%s\n", player->cur_action);
	printf("succes %s\n", player->cur_action);
	(*obj) = *obj + 1;
	*o = *o - 1;
	player->cur_action = player->action[0];
	if (player->cur_action != NULL)
	{
		ft_destroy_action(player, 0);
		dprintf(player->sock, "%s", player->cur_action);
		printf("current : %s", player->cur_action);
	}
	e->graph.modif = 0;
}

static void		st_check_action_poser(t_player *player, t_env *e)
{
	if (!strcmp(POSER_L, player->cur_action))
		st_action_poser(e->cur_player, e, &e->map[player->y][player->x].l,
						&player->inventory.l);
	else if (!strcmp(POSER_D, player->cur_action))
		st_action_poser(e->cur_player, e, &e->map[player->y][player->x].d,
						&player->inventory.d);
	else if (!strcmp(POSER_S, player->cur_action))
		st_action_poser(e->cur_player, e, &e->map[player->y][player->x].s,
						&player->inventory.s);
	else if (!strcmp(POSER_M, player->cur_action))
		st_action_poser(e->cur_player, e, &e->map[player->y][player->x].m,
						&player->inventory.m);
	else if (!strcmp(POSER_P, player->cur_action))
		st_action_poser(e->cur_player, e, &e->map[player->y][player->x].p,
						&player->inventory.p);
	else if (!strcmp(POSER_T, player->cur_action))
		st_action_poser(e->cur_player, e, &e->map[player->y][player->x].t,
						&player->inventory.t);
	else if (!strcmp(POSER_FOOD, player->cur_action))
		st_action_poser(e->cur_player, e, &e->map[player->y][player->x].food,
						&player->inventory.food);
}

void			ft_action_poser(t_player *player, t_env *e)
{
	if (!strcmp(player->read, OK))
		st_check_action_poser(player, e);
	else if (!strcmp(player->read, KO))
		ft_action_ko(player, e);
}
