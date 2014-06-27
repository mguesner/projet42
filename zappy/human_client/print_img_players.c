/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_players.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:50:33 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:50:34 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void		st_send_img_lvl_cur(t_env *e, int *y)
{
	if (e->cur_player->level == 1)
		ft_print_img(e, OBJ_PLAYER_CUR_1.ptr, 25, *y);
	else if (e->cur_player->level == 2)
		ft_print_img(e, OBJ_PLAYER_CUR_2.ptr, 25, *y);
	else if (e->cur_player->level == 3)
		ft_print_img(e, OBJ_PLAYER_CUR_3.ptr, 25, *y);
	else if (e->cur_player->level == 4)
		ft_print_img(e, OBJ_PLAYER_CUR_4.ptr, 25, *y);
	else if (e->cur_player->level == 5)
		ft_print_img(e, OBJ_PLAYER_CUR_5.ptr, 25, *y);
	else if (e->cur_player->level == 6)
		ft_print_img(e, OBJ_PLAYER_CUR_6.ptr, 25, *y);
	else if (e->cur_player->level == 7)
		ft_print_img(e, OBJ_PLAYER_CUR_7.ptr, 25, *y);
	else if (e->cur_player->level == 8)
		ft_print_img(e, OBJ_PLAYER_CUR_8.ptr, 25, *y);
	*y += 100;
}

static void		st_send_img_lvl_free(t_env *e, t_player *player, int *y)
{
	if (player->level == 1)
		ft_print_img(e, OBJ_PLAYER_FREE_1.ptr, 25, *y);
	else if (player->level == 2)
		ft_print_img(e, OBJ_PLAYER_FREE_2.ptr, 25, *y);
	else if (player->level == 3)
		ft_print_img(e, OBJ_PLAYER_FREE_3.ptr, 25, *y);
	else if (player->level == 4)
		ft_print_img(e, OBJ_PLAYER_FREE_4.ptr, 25, *y);
	else if (player->level == 5)
		ft_print_img(e, OBJ_PLAYER_FREE_5.ptr, 25, *y);
	else if (player->level == 6)
		ft_print_img(e, OBJ_PLAYER_FREE_6.ptr, 25, *y);
	else if (player->level == 7)
		ft_print_img(e, OBJ_PLAYER_FREE_7.ptr, 25, *y);
	else if (player->level == 8)
		ft_print_img(e, OBJ_PLAYER_FREE_8.ptr, 25, *y);
	*y += 75;
}

static void		st_send_img_lvl_ot(t_env *e, t_player *player, int *y)
{
	if (player->level == 1)
		ft_print_img(e, OBJ_PLAYER_OT_1.ptr, 25, *y);
	else if (player->level == 2)
		ft_print_img(e, OBJ_PLAYER_OT_2.ptr, 25, *y);
	else if (player->level == 3)
		ft_print_img(e, OBJ_PLAYER_OT_3.ptr, 25, *y);
	else if (player->level == 4)
		ft_print_img(e, OBJ_PLAYER_OT_4.ptr, 25, *y);
	else if (player->level == 5)
		ft_print_img(e, OBJ_PLAYER_OT_5.ptr, 25, *y);
	else if (player->level == 6)
		ft_print_img(e, OBJ_PLAYER_OT_6.ptr, 25, *y);
	else if (player->level == 7)
		ft_print_img(e, OBJ_PLAYER_OT_7.ptr, 25, *y);
	else if (player->level == 8)
		ft_print_img(e, OBJ_PLAYER_OT_8.ptr, 25, *y);
	*y += 75;
}

void			ft_print_img_players(t_env *e)
{
	int			i;
	int			y;

	i = 0;
	y = 25;
	while (i < e->nb_player)
	{
		if (e->cur_player == &e->players[i])
			st_send_img_lvl_cur(e, &y);
		else if (e->players[i].cur_action == NULL)
			st_send_img_lvl_free(e, &e->players[i], &y);
		else
			st_send_img_lvl_ot(e, &e->players[i], &y);
		i++;
	}
}
