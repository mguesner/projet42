/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast_gfx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 18:06:14 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/17 15:24:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "zappy.h"
#include <stdio.h>

void	broadcast_gfx(t_env *e, t_clients *player, char *msg)
{
	char	tmp[4096];

	sprintf(tmp, "bc %d %s %s\n", player->nb, player->name, msg);
	maj_gfx(e, tmp);
}
