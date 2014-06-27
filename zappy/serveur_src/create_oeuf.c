/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_oeuf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 13:38:40 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/26 14:06:40 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

t_oeuf	*create_oeuf(t_env *e, t_clients *player)
{
	t_oeuf	*ret;
	t_list	*tmp;

	ret = ft_memalloc(sizeof(t_oeuf));
	ret->x = player->X;
	ret->y = player->Y;
	tmp = e->names;
	while (tmp)
	{
		if (!strcmp(player->name, tmp->name))
			break ;
		tmp = tmp->next;
	}
	ret->nb = tmp->nb_player++;
	ret->life = 0;
	ret->eclo = 600;
	ret->team = ft_strdup(player->name);
	ret->next = NULL;
	return (ret);
}
