/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:21:24 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:21:25 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static int			st_usage(char *str)
{
	fprintf(stderr, "Usage: %s -n  <team> -p <port> [-h <hostname>]\n", str);
	fprintf(stderr, "-n nom d'equipe\n-p port\n");
	fprintf(stderr, "-h nom de la machine par defaut c'est le localhost\n");
	return (-1);
}

static void			st_init_egg(t_env *e)
{
	int				i;

	i = 0;
	e->egg_use = 0;
	while (i < MAX_PLAYER)
	{
		e->egg[i].t = 0;
		e->egg[i].status = 0;
		i++;
	}
}

static void			st_init_env(t_env *e)
{
	int				i;

	i = 0;
	e->graph.mlx = NULL;
	e->graph.win = NULL;
	e->graph.status = 0;
	st_init_egg(e);
	e->connect = 0;
	e->order_connect = 0;
	while (i < MAX_PLAYER)
	{
		ft_init_player(e, i);
		i++;
	}
	e->nb_player = 0;
	e->max_fd = 0;
	e->map = NULL;
	e->x = 0;
	e->y = 0;
	e->view.case_y = 0;
	e->view.case_x = 0;
	e->graph.start_y = 0;
	e->graph.start_x = 0;
	e->graph.modif = 0;
	pthread_mutex_init(&e->mutex, NULL);
}

int					main(int ac, char **av, char **environ)
{
	t_env			e;
	int				ret;

	if (!environ[0])
		return (0);
	if (ft_parse_option_human(ac, av, &e) == -1)
		return (st_usage(av[0]));
	st_init_env(&e);
	if ((ret = ft_connect_serveur(&e)) <= 0)
		ft_check_error_connect(ret);
	while (e.players[e.nb_player].status < 5)
		ft_read(&e.players[e.nb_player], &e);
	e.nb_player++;
	e.cur_player = &e.players[0];
	if ((ret = pthread_create(&e.graph.graph, NULL, ft_mlx, (void *)&e)))
		return (0);
	ft_check_select(&e);
	return (0);
}
