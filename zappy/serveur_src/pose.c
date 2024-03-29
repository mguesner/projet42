/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 11:07:34 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 18:36:28 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <stdio.h>

static void	pose2(t_env *e, t_clients *player, char *msg, char **tab)
{
	if (tab[1] && !ft_strcmp(tab[1], "nourriture") && player->life / 126
		&& (player->life -= 126))
		e->map[player->Y][player->X].nourriture++;
	else if (tab[1] && !ft_strcmp(tab[1], "linemate") && player->linemate
		&& player->linemate--)
		e->map[player->Y][player->X].linemate++;
	else if (tab[1] && !ft_strcmp(tab[1], "deraumere") && player->deraumere
		&& player->deraumere--)
		e->map[player->Y][player->X].deraumere++;
	else if (tab[1] && !ft_strcmp(tab[1], "sibur") && player->sibur
		&& player->sibur--)
		e->map[player->Y][player->X].sibur++;
	else if (tab[1] && !ft_strcmp(tab[1], "mendiane") && player->mendiane
		&& player->mendiane--)
		e->map[player->Y][player->X].mendiane++;
	else if (tab[1] && !ft_strcmp(tab[1], "phiras") && player->phiras
		&& player->phiras--)
		e->map[player->Y][player->X].phiras++;
	else if (tab[1] && !ft_strcmp(tab[1], "thystame") && player->thystame
		&& player->thystame--)
		e->map[player->Y][player->X].thystame++;
	else
		ft_strcpy(msg, "ko\n");
}

void		pose(t_env *e, t_clients *player)
{
	char	**tab;
	char	msg[4];
	char	tmp[BUF_SIZE];

	tab = ft_strsplit(player->arg[0], ' ');
	ft_strcpy(msg, "ok\n");
	pose2(e, player, msg, tab);
	sprintf(tmp, "inv %d %d %d %d %d %d %d %d %s\n", player->nb
				, player->life, player->linemate
				, player->deraumere, player->sibur, player->mendiane
				, player->phiras, player->thystame, player->name);
	sprintf(tmp + ft_strlen(tmp), "inside %d %d %d %d %d %d %d %d %d\n"
		, player->X, player->Y
		, e->map[player->Y][player->X].nourriture
		, e->map[player->Y][player->X].linemate
		, e->map[player->Y][player->X].deraumere
		, e->map[player->Y][player->X].sibur
		, e->map[player->Y][player->X].mendiane
		, e->map[player->Y][player->X].phiras
		, e->map[player->Y][player->X].thystame);
	maj_gfx(e, tmp);
	next_action(player);
	ft_strcat(player->buf_write, msg);
	ft_tabdel(&tab);
}
