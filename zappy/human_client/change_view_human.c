/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view_human.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:20:19 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:20:20 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void	st_change_view_nord(t_player *player, t_env *e)
{
	int		lvl_y;
	int		i;
	int		x_min;
	int		x_max;
	int		j;

	lvl_y = player->y;
	i = 0;
	while (i <= player->level)
	{
		ft_check_view_case(e, lvl_y, player->x);
		j = 1;
		x_min = player->x;
		x_max = player->x;
		while (j <= i)
		{
			ft_check_coor_x(&x_min, e, -1);
			ft_check_coor_x(&x_max, e, 1);
			ft_check_view_case(e, lvl_y, x_min);
			ft_check_view_case(e, lvl_y, x_max);
			j++;
		}
		i++;
		ft_check_coor_y(&lvl_y, e, -1);
	}
}

static void	st_change_view_est(t_player *player, t_env *e)
{
	int		y_min;
	int		y_max;
	int		i;
	int		lvl_x;
	int		j;

	lvl_x = player->x;
	i = 0;
	while (i <= player->level)
	{
		ft_check_view_case(e, player->y, lvl_x);
		j = 1;
		y_min = player->y;
		y_max = player->y;
		while (j <= i)
		{
			ft_check_coor_y(&y_min, e, -1);
			ft_check_coor_y(&y_max, e, 1);
			ft_check_view_case(e, y_min, lvl_x);
			ft_check_view_case(e, y_max, lvl_x);
			j++;
		}
		i++;
		ft_check_coor_x(&lvl_x, e, 1);
	}
}

static void	st_change_view_sud(t_player *player, t_env *e)
{
	int		lvl_y;
	int		i;
	int		x_min;
	int		x_max;
	int		j;

	lvl_y = player->y;
	i = 0;
	while (i <= player->level)
	{
		ft_check_view_case(e, lvl_y, player->x);
		j = 1;
		x_min = player->x;
		x_max = player->x;
		while (j <= i)
		{
			ft_check_coor_x(&x_min, e, -1);
			ft_check_coor_x(&x_max, e, 1);
			ft_check_view_case(e, lvl_y, x_min);
			ft_check_view_case(e, lvl_y, x_max);
			j++;
		}
		i++;
		ft_check_coor_y(&lvl_y, e, 1);
	}
}

static void	st_change_view_ouest(t_player *player, t_env *e)
{
	int		y_min;
	int		y_max;
	int		i;
	int		lvl_x;
	int		j;

	lvl_x = player->x;
	i = 0;
	while (i <= player->level)
	{
		ft_check_view_case(e, player->y, lvl_x);
		j = 1;
		y_min = player->y;
		y_max = player->y;
		while (j <= i)
		{
			ft_check_coor_y(&y_min, e, -1);
			ft_check_coor_y(&y_max, e, 1);
			ft_check_view_case(e, y_min, lvl_x);
			ft_check_view_case(e, y_max, lvl_x);
			j++;
		}
		i++;
		ft_check_coor_x(&lvl_x, e, -1);
	}
}

void		ft_change_view(t_player *player, t_env *e)
{
	if (player->type == FD_PLAYER)
	{
		if (player->view == 0)
			st_change_view_nord(player, e);
		else if (player->view == 1)
			st_change_view_est(player, e);
		else if (player->view == 2)
			st_change_view_sud(player, e);
		else if (player->view == 3)
			st_change_view_ouest(player, e);
	}
}
