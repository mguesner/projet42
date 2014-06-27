/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voir.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:52:59 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/24 11:17:04 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

static void	voir2(t_env *e, t_clients *player, int i, int j)
{
	int		x;
	int		y;

	if (player->orient == 0)
	{
		x = modulo((player->X - ((i + 1) * 2 + 1) / 2) + j, e->width);
		y = modulo(player->Y - (i + 1), e->height);
	}
	else if (player->orient == 1)
	{
		x = modulo(player->X + (i + 1), e->width);
		y = modulo((player->Y - ((i + 1) * 2 + 1) / 2) + j, e->height);
	}
	else if (player->orient == 2)
	{
		x = modulo((player->X + ((i + 1) * 2 + 1) / 2) - j, e->width);
		y = modulo(player->Y + (i + 1), e->height);
	}
	else
	{
		x = modulo(player->X - (i + 1), e->width);
		y = modulo((player->Y + ((i + 1) * 2 + 1) / 2) - j, e->height);
	}
	inside(player, e->map[y][x], 0);
}

void		voir(t_env *e, t_clients *player)
{
	int		i;
	int		j;

	i = -1;
	ft_strcat(player->buf_write, "{");
	inside(player, e->map[player->Y][player->X], 1);
	ft_strcat(player->buf_write, ", ");
	while (++i < player->lvl && (j = -1))
		while (++j < ((i + 1) * 2 + 1))
		{
			voir2(e, player, i, j);
			if (!((i == player->lvl - 1) && (j == (i + 1) * 2)))
				ft_strcat(player->buf_write, ", ");
		}
	strcat(player->buf_write, "}\n");
	next_action(player);
}
