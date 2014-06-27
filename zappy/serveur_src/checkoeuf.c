/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkoeuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 14:13:46 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 13:36:11 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <stdio.h>

static void		checkoeuf2(t_env *e, t_list *tmp2, t_oeuf *tmp)
{
	char	tmp3[4096];

	while (tmp2)
	{
		if (!ft_strcmp(tmp2->name, tmp->team))
		{
			tmp2->nb_connect--;
			sprintf(tmp3, "mort %d %s\n", tmp->nb, tmp->team);
			maj_gfx(e, tmp3);
			break ;
		}
		tmp2 = tmp2->next;
	}
	destroy_oeuf(e, tmp);
}

static void		checkoeuf3(t_env *e, t_list *tmp2, t_oeuf *tmp)
{
	char	tmp3[4096];

	tmp->eclo--;
	if (tmp->eclo == 0)
	{
		tmp->life = 1260;
		while (tmp2)
		{
			if (!ft_strcmp(tmp2->name, tmp->team))
			{
				sprintf(tmp3, "eclo %d %s\n", tmp->nb, tmp->team);
				maj_gfx(e, tmp3);
				tmp2->nb_connect++;
				break ;
			}
			tmp2 = tmp2->next;
		}
	}
}

void			checkoeuf(t_env *e)
{
	t_oeuf	*tmp;
	t_list	*tmp2;

	tmp = e->oeufs;
	tmp2 = e->names;
	while (tmp)
	{
		if (tmp->eclo > 0)
			checkoeuf3(e, tmp2, tmp);
		else if (tmp->life > 0)
			tmp->life--;
		else
			checkoeuf2(e, tmp2, tmp);
		tmp = tmp->next;
	}
}
