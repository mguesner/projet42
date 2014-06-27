/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initenv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 14:47:45 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 18:29:03 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/resource.h>
#include <libft.h>
#include "zappy.h"

static void	initenv2(t_env *e)
{
	t_list			*tmp;

	tmp = e->names;
	while (tmp && !(tmp->nb_player = 0))
	{
		tmp->nb_connect = e->nb;
		tmp->nb_oeuf = 0;
		tmp = tmp->next;
	}
}

void		initenv(t_env *e)
{
	struct rlimit	rlp;
	int				i;
	int				j;

	if (getrlimit(RLIMIT_NOFILE, &rlp) == -1)
		ft_perror("getrlimit");
	e->max_clients = rlp.rlim_cur;
	e->clients = (t_clients *)ft_memalloc(sizeof(t_clients)
		* e->max_clients);
	initenv2(e);
	e->oeufs = NULL;
	if (e->height < 1 || e->width < 1)
		ft_error("bad size map");
	e->map = ft_memalloc(e->height * sizeof(t_case));
	i = -1;
	while (++i < e->height && (j = -1))
	{
		e->map[i] = ft_memalloc(e->width * sizeof(t_case));
		while (++j < e->width)
			e->map[i][j] = genere_case();
	}
}
