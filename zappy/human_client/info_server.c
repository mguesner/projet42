/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:21:31 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:21:32 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void		st_init_case(t_case *place, int x, int y)
{
	place->view = 0;
	place->food = 0;
	place->l = 0;
	place->d = 0;
	place->s = 0;
	place->m = 0;
	place->p = 0;
	place->t = 0;
	place->my_player = 0;
	place->other_player = 0;
	place->y = y;
	place->x = x;
}

static void		st_create_map(t_env *e, int y, int x)
{
	int		j;
	int		i;

	j = 0;
	e->map = (t_case **)malloc(sizeof(t_case *) * (y + 1));
	while (j < y)
	{
		e->map[j] = (t_case *)malloc(sizeof(t_case) * x);
		i = 0;
		while (i < x)
		{
			st_init_case(&e->map[j][i], i, j);
			i++;
		}
		j++;
	}
	e->map[j] = NULL;
	if ((x * 100) < WIN_SIZE_X)
		e->graph.start_x = (WIN_SIZE_X - (x * 100)) / 2;
}

void			ft_check_coor(t_env *e, t_player *player)
{
	char	**tab;
	int		y;
	int		x;

	tab = ft_splitspace(player->read);
	if (ft_tablen((void **)tab) != 2)
	{
		printf("problem server\n");
		exit(-1);
	}
	x = atoi(tab[0]);
	y = atoi(tab[1]);
	if (x <= 0 || y <= 0)
	{
		printf("coor incoherente\n");
		exit(-1);
	}
	ft_delfulltab((void ***)&tab);
	st_create_map(e, y, x);
	player->x = x / 2;
	player->y = y / 2;
	e->map[player->y][player->x].my_player = player->num_player;
	e->y = y;
	e->x = x;
}
