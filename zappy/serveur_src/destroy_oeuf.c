/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_oeuf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 17:14:17 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/24 17:38:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	destroy_oeuf(t_env *e, t_oeuf *oeuf)
{
	t_oeuf	*tmp;

	tmp = e->oeufs;
	if (tmp->nb == oeuf->nb && !ft_strcmp(tmp->team, oeuf->team))
	{
		e->oeufs = e->oeufs->next;
	}
	else
	{
		while (tmp->next && tmp->next->nb != oeuf->nb
			&& ft_strcmp(tmp->next->team, oeuf->team))
			tmp = tmp->next;
		tmp->next = oeuf->next;
	}
	ft_strdel(&oeuf->team);
	ft_memdel((void **)&oeuf);
}
