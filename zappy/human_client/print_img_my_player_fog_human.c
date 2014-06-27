/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_my_player_fog_human.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:25:31 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:25:32 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void st_print_my_player_cur(t_env *e, t_player *player, int x, int y)
{
	if (player->view == VIEW_NORTH)
		ft_print_img(e, OBJ_FOG_NORTH_CUR.ptr, x, y);
	else if (player->view == VIEW_EAST)
		ft_print_img(e, OBJ_FOG_EAST_CUR.ptr, x, y);
	else if (player->view == VIEW_SOUTH)
		ft_print_img(e, OBJ_FOG_SOUTH_CUR.ptr, x, y);
	else
		ft_print_img(e, OBJ_FOG_WEST_CUR.ptr, x, y);
}

static void st_print_my_player_free(t_env *e, t_player *player, int x, int y)
{
	if (player->view == VIEW_NORTH)
		ft_print_img(e, OBJ_FOG_NORTH_FREE.ptr, x, y);
	else if (player->view == VIEW_EAST)
		ft_print_img(e, OBJ_FOG_EAST_FREE.ptr, x, y);
	else if (player->view == VIEW_SOUTH)
		ft_print_img(e, OBJ_FOG_SOUTH_FREE.ptr, x, y);
	else
		ft_print_img(e, OBJ_FOG_WEST_FREE.ptr, x, y);
}

static void st_print_my_player_ot(t_env *e, t_player *player, int x, int y)
{
	if (player->view == VIEW_NORTH)
		ft_print_img(e, OBJ_FOG_NORTH_OT.ptr, x, y);
	else if (player->view == VIEW_EAST)
		ft_print_img(e, OBJ_FOG_EAST_OT.ptr, x, y);
	else if (player->view == VIEW_SOUTH)
		ft_print_img(e, OBJ_FOG_SOUTH_OT.ptr, x, y);
	else
		ft_print_img(e, OBJ_FOG_WEST_OT.ptr, x, y);
}

static void	st_search_player_case(t_env *e, t_case *field, int x, int y)
{
	int		i;
	int		count;

	i = 0;
	count = -1;
	while (i < MAX_PLAYER)
	{
		if (e->players[i].y == field->y && e->players[i].x == field->x)
		{
			if (e->players[i].cur_action == NULL || count == -1)
				count = i;
		}
		i++;
	}
	if (count == -1)
		printf("problem\n");
	else if (e->players[count].cur_action == NULL)
		st_print_my_player_free(e, &e->players[count], x, y);
	else
		st_print_my_player_ot(e, &e->players[count], x, y);
}

void		ft_print_img_my_player_fog(t_env *e, t_case *field, int x, int y)
{
	if (e->cur_player && e->cur_player->x == field->x
		&& e->cur_player->y == field->y)
		st_print_my_player_cur(e, e->cur_player, x + 40, y + 40);
	else
		st_search_player_case(e, field, x + 40, y + 40);
}
