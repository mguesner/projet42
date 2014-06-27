/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_gfx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 16:32:42 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/13 17:48:46 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <stdio.h>

void	connect_gfx(t_env *e, t_clients *player)
{
	char	tmp[4096];

	sprintf(tmp, "connect %d %d %d %d %d %s\n", player->nb, player->X
		, player->Y, player->orient, player->lvl, player->name);
	maj_gfx(e, tmp);
}
