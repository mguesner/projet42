/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expulse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 13:33:39 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/12 14:41:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

static void expulse2(int nb, t_clients *player)
{
	if (nb)
		ft_strcat(player->buf_write, "ok\n");
	else
		ft_strcat(player->buf_write, "ko\n");
	ft_memcpy(player->fct_action, player->fct_action + 1
		, sizeof(*player->fct_action) * player->i_action);
	ft_memcpy(player->action, player->action + 1
		, sizeof(*player->action) * player->i_action);
	ft_memcpy(player->arg, player->arg + 1
		, sizeof(*player->arg) * player->i_action);
	player->i_action--;
}

void		expulse3(t_env *e, t_clients *player, int i)
{
	char	*tmp;

	ft_strcat(e->clients[i].buf_write, "deplacement ");
	tmp = ft_itoa(ex_dir(player, &e->clients[i]));
	ft_strcat(e->clients[i].buf_write, tmp);
	ft_strcat(e->clients[i].buf_write, "\n");
}

void		expulse(t_env *e, t_clients *player)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	ft_printf("expulse\n");
	while (++i <= e->max_fd)
		if (e->clients[i].type == CLIENT_CLIENT && player->X == e->clients[i].X
			&& player->Y == e->clients[i].Y && (e->clients[i].nb != player->nb
				|| ft_strcmp(player->name, e->clients[i].name)))
		{
			e->map[player->Y][player->X].joueur--;
			if (player->orient == 1)
				e->clients[i].X = modulo(e->clients[i].X + 1, e->width);
			if (player->orient == 2)
				e->clients[i].Y = modulo(e->clients[i].Y + 1, e->height);
			if (player->orient == 3)
				e->clients[i].X = modulo(e->clients[i].X - 1, e->width);
			if (player->orient == 0)
				e->clients[i].Y = modulo(e->clients[i].Y - 1, e->height);
			e->map[e->clients[i].Y][e->clients[i].X].joueur++;
			expulse3(e, player, i);
			nb++;
		}
	expulse2(nb, player);
}
