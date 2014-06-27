/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_case_humanc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:20:06 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:20:07 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void		ft_add_player_case(t_env *e, int new_y, int new_x)
{
	e->map[new_y][new_x].my_player++;
}

void		ft_del_player_case(t_player *player, t_env *e)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < MAX_PLAYER)
	{
		if (e->players[i].y == player->y && e->players[i].x == player->x)
			count++;
		i++;
	}
	if (count == 1)
		e->map[player->y][player->x].my_player--;
}

void		ft_change_case(t_player *player, t_env *e, int new_y, int new_x)
{
	ft_check_coor_x(&new_x, e, 0);
	ft_check_coor_y(&new_y, e, 0);
	ft_del_player_case(player, e);
	ft_add_player_case(e, new_y, new_x);
	ft_change_view(player, e);
	player->y = new_y;
	player->x = new_x;
}
