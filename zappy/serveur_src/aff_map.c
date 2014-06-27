/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 11:30:58 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/17 11:58:08 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdio.h>

void	aff_map(t_env *e, t_clients *player)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i <= e->max_fd)
	{
		if (e->clients[i].type == CLIENT_GRAPH)
		{
			if (player)
				dprintf(i, "mort %d %s\n", player->nb, player->name);
			j = -1;
			while (++j < e->height && (k = -1))
				while (++k < e->width)
					contenue(e, j, k, i);
		}
	}
}
