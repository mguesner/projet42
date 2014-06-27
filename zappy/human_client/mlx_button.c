/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_button.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:27:44 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:27:45 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void		st_button_2(int keycode, t_env *e)
{
	if (keycode == 108)
		ft_check_action_mlx(e->cur_player, INCANT, e);
	else if (keycode == 116)
		e->cur_player->start_action = PRENDRE;
	else if (keycode == 112)
		e->cur_player->start_action = POSER;
	else if (keycode == 105)
		ft_check_action_mlx(e->cur_player, INVENTAIRE, e);
	else if (keycode == 65293 && e->cur_player->inventory.status == 1)
	{
		ft_init_inventaire(e->cur_player);
		e->graph.modif = 0;
	}
}

static void		st_exit(t_env *e)
{
	e->graph.status = 2;
	mlx_destroy_window(e->graph.mlx, e->graph.win);
	exit(0);
}

static void		st_check_fd_player(int keycode, t_env *e)
{
	if (e->cur_player->start_action == PRENDRE)
		ft_check_action_prendre(e, keycode);
	else if (e->cur_player->start_action == POSER)
		ft_check_action_poser(e, keycode);
	e->cur_player->start_action = 0;
	printf("%d\n", keycode);
	if (keycode == 119)
		ft_check_action_mlx(e->cur_player, AVANCE, e);
	else if (keycode == 97)
		ft_check_action_mlx(e->cur_player, GAUCHE, e);
	else if (keycode == 100)
		ft_check_action_mlx(e->cur_player, DROITE, e);
	else if (keycode == 118)
		ft_check_action_mlx(e->cur_player, VOIR, e);
	else
		st_button_2(keycode, e);
}

int				ft_button(int keycode, t_env *e)
{
	if (keycode == 65307)
		st_exit(e);
	else if (keycode == 99 && e->connect > 0 && e->order_connect == 0)
		e->order_connect++;
	else if (keycode == 65362)
		ft_change_camera(e, 0, CAMERA_UP);
	else if (keycode == 65364)
		ft_change_camera(e, 0, CAMERA_DOWN);
	else if (keycode == 65361)
		ft_change_camera(e, CAMERA_LEFT, 0);
	else if (keycode == 65363)
		ft_change_camera(e, CAMERA_RIGHT, 0);
	else if (e->cur_player->type == FD_PLAYER)
		st_check_fd_player(keycode, e);
	return (0);
}
