/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 18:55:42 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/26 14:46:26 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	eat(t_env *e, t_clients *client)
{
	int		x;
	int		y;
	char	tmp2[BUF_SIZE];

	client->life--;
	if (!(client->life % 126))
	{
		x = rand() % e->width;
		y = rand() % e->height;
		e->map[y][x].nourriture++;
		sprintf(tmp2, "inside %d %d %d %d %d %d %d %d %d\n", x, y
			, e->map[y][x].nourriture, e->map[y][x].linemate
			, e->map[y][x].deraumere, e->map[y][x].sibur, e->map[y][x].mendiane
			, e->map[y][x].phiras, e->map[y][x].thystame);
		maj_gfx(e, tmp2);
	}
	if (client->life <= 0)
	{
		explode_player(e, client);
		sprintf(tmp2, "mort %d %s\n", client->nb, client->name);
		maj_gfx(e, tmp2);
		ft_strcpy(client->buf_write, "mort\n");
	}
}
