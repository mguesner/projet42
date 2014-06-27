/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pond.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 13:23:42 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 14:10:26 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	pond(t_env *e, t_clients *player)
{
	t_oeuf	*tmp;

	if (!e->oeufs)
	{
		e->oeufs = create_oeuf(e, player);
		tmp = e->oeufs;
	}
	else
	{
		tmp = e->oeufs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_oeuf(e, player);
		tmp = tmp->next;
	}
	next_action(player);
	ft_strcat(player->buf_write, "ok\n");
	pond_gfx(e, tmp);
}
