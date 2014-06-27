/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 08:37:03 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/26 16:57:48 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <stdio.h>

static void	prend2(t_env *e, t_clients *player, char *msg, char **tab)
{
	if (tab[1] && !ft_strcmp(tab[1], "nourriture")
		&& e->map[player->Y][player->X].nourriture > 0 && (player->life += 126))
		e->map[player->Y][player->X].nourriture--;
	else if (tab[1] && !ft_strcmp(tab[1], "linemate")
		&& e->map[player->Y][player->X].linemate > 0 && (player->linemate++))
		e->map[player->Y][player->X].linemate--;
	else if (tab[1] && !ft_strcmp(tab[1], "deraumere")
		&& e->map[player->Y][player->X].deraumere > 0 && (player->deraumere++))
		e->map[player->Y][player->X].deraumere--;
	else if (tab[1] && !ft_strcmp(tab[1], "sibur")
		&& e->map[player->Y][player->X].sibur > 0 && (player->sibur++))
		e->map[player->Y][player->X].sibur--;
	else if (tab[1] && !ft_strcmp(tab[1], "mendiane")
		&& e->map[player->Y][player->X].mendiane > 0 && (player->mendiane++))
		e->map[player->Y][player->X].mendiane--;
	else if (tab[1] && !ft_strcmp(tab[1], "phiras")
		&& e->map[player->Y][player->X].phiras > 0 && (player->phiras++))
		e->map[player->Y][player->X].phiras--;
	else if (tab[1] && !ft_strcmp(tab[1], "thystame")
		&& e->map[player->Y][player->X].thystame > 0 && (player->thystame++))
		e->map[player->Y][player->X].thystame--;
	else
		ft_strcpy(msg, "ko\n");
}

void		prend(t_env *e, t_clients *player)
{
	char	**tab;
	char	msg[4];
	char	tmp[BUF_SIZE];

	tab = ft_strsplit(player->arg[0], ' ');
	ft_strcpy(msg, "ok\n");
	prend2(e, player, msg, tab);
	sprintf(tmp, "inv %d %d %d %d %d %d %d %d %s\n", player->nb
				, player->life, player->linemate
				, player->deraumere, player->sibur, player->mendiane
				, player->phiras, player->thystame, player->name);
	sprintf(tmp + strlen(tmp), "inside %d %d %d %d %d %d %d %d %d\n"
		, player->X, player->Y, e->map[player->Y][player->X].nourriture
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
