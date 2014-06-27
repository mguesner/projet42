/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 16:00:06 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/26 14:31:58 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <stdlib.h>
#include <math.h>

static int		broadcast2(int v_x, int v_y, t_env *e, int i)
{
	if (v_x >= 0 && v_y >= 0 && abs(v_x) > abs(v_y))
		return (e->clients[i].orient * 2 + 3) % 8 != 0
		? (e->clients[i].orient * 2 + 3) % 8 : 8;
	else if (v_x >= 0 && v_y < 0 && abs(v_x) > abs(v_y))
		return (e->clients[i].orient * 2 + 3) % 8 != 0
		? (e->clients[i].orient * 2 + 3) % 8 : 8;
	else if (v_x < 0 && v_y < 0 && abs(v_x) > abs(v_y))
		return (e->clients[i].orient * 2 + 7) % 8 != 0
		? (e->clients[i].orient * 2 + 7) % 8 : 8;
	else if (v_x < 0 && v_y >= 0 && abs(v_x) > abs(v_y))
		return (e->clients[i].orient * 2 + 7) % 8 != 0
		? (e->clients[i].orient * 2 + 7) % 8 : 8;
	else if (v_x >= 0 && v_y >= 0 && abs(v_x) < abs(v_y))
		return (e->clients[i].orient * 2 + 1) % 8 != 0
		? (e->clients[i].orient * 2 + 1) % 8 : 8;
	else if (v_x >= 0 && v_y < 0 && abs(v_x) < abs(v_y))
		return (e->clients[i].orient * 2 + 5) % 8 != 0
		? (e->clients[i].orient * 2 + 5) % 8 : 8;
	else if (v_x < 0 && v_y < 0 && abs(v_x) < abs(v_y))
		return (e->clients[i].orient * 2 + 5) % 8 != 0
		? (e->clients[i].orient * 2 + 5) % 8 : 8;
	else if (v_x < 0 && v_y >= 0 && abs(v_x) < abs(v_y))
		return (e->clients[i].orient * 2 + 1) % 8 != 0
		? (e->clients[i].orient * 2 + 1) % 8 : 8;
	return (0);
}

static int		broadcast4(t_env *e, int i, t_clients *player, int mode)
{
	if (mode == 'x')
		return (abs(e->clients[i].X - player->X)
		< abs(e->width - e->clients[i].X + player->X)
		? e->clients[i].X - player->X
		: e->width - e->clients[i].X + player->X);
	if (mode == 'y')
		return (abs(e->clients[i].Y - player->Y)
		< abs(e->height - e->clients[i].Y + player->Y)
		? e->clients[i].Y - player->Y
		: e->height - e->clients[i].Y + player->Y);
	return (0);
}

static void		broadcast5(t_env *e, int i, char *msg, int source)
{
	char	*tmp;

	ft_strcat(e->clients[i].buf_write, "message ");
	tmp = ft_itoa(source);
	ft_strcat(e->clients[i].buf_write, tmp);
	ft_strdel(&tmp);
	ft_strcat(e->clients[i].buf_write, ",");
	ft_strcat(e->clients[i].buf_write, msg);
	ft_strcat(e->clients[i].buf_write, "\n");
}

static void		broadcast3(t_env *e, int i, char *msg, t_clients *player)
{
	int		v_x;
	int		v_y;
	int		source;

	v_x = broadcast4(e, i, player, 'x');
	v_y = broadcast4(e, i, player, 'y');
	if (v_x == 0 && v_y == 0)
		source = 0;
	else if (v_x >= 0 && v_y >= 0 && abs(v_x) == abs(v_y))
		source = e->clients[i].orient * 2 + 2;
	else if (v_x >= 0 && v_y < 0 && abs(v_x) == abs(v_y))
		source = (e->clients[i].orient * 2 + 4) % 8 != 0
		? (e->clients[i].orient * 2 + 4) % 8 : 8;
	else if (v_x < 0 && v_y < 0 && abs(v_x) == abs(v_y))
		source = (e->clients[i].orient * 2 + 6) % 8 != 0
		? (e->clients[i].orient * 2 + 6) % 8 : 8;
	else if (v_x < 0 && v_y >= 0 && abs(v_x) == abs(v_y))
		source = (e->clients[i].orient * 2 + 8) % 8 != 0
		? (e->clients[i].orient * 2 + 8) % 8 : 8;
	else
		source = broadcast2(v_x, v_y, e, i);
	broadcast5(e, i, msg, source);
}

void			broadcast(t_env *e, t_clients *player)
{
	int		i;
	char	*msg;

	i = -1;
	msg = strchr(player->arg[0], ' ') + 1;
	ft_strcat(player->buf_write, "ok\n");
	while (msg && ++i <= e->max_fd)
		if (e->clients[i].type == CLIENT_CLIENT)
			broadcast3(e, i, msg, player);
	broadcast_gfx(e, player, msg);
	memcpy(player->fct_action, player->fct_action + 1
		, sizeof(*player->fct_action) * player->i_action);
	memcpy(player->action, player->action + 1
		, sizeof(*player->action) * player->i_action);
	memcpy(player->arg, player->arg + 1
		, sizeof(*player->arg) * player->i_action);
	player->i_action--;
}
