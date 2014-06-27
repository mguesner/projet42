/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isoeuf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 16:58:48 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 11:07:30 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

int		isoeuf(t_env *e, t_clients *player, char *cmd)
{
	t_oeuf	*tmp;

	tmp = e->oeufs;
	while (tmp)
	{
		if (!ft_strcmp(tmp->team, cmd))
		{
			player->nb = tmp->nb;
			player->Y = tmp->y;
			player->X = tmp->x;
			player->life = tmp->life;
			destroy_oeuf(e, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
