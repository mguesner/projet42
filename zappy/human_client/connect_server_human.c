/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_server_human.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:20:40 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:20:42 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void				ft_check_error_connect(int ret)
{
	if (ret == -2)
		ft_error("getprotobyname", -1);
	else if (ret == -3)
		ft_error("socket", -1);
	else if (ret == -4)
		ft_error("connect", -1);
}

int					ft_connect_serveur(t_env *e)
{
	t_protoent		*proto;
	t_sockaddr_in	sin;

	if (!(proto = getprotobyname("tcp")))
		return (-2);
	if ((e->players[e->nb_player].sock = socket(PF_INET, SOCK_STREAM,
										proto->p_proto)) == -1)
		return (-3);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(e->port);
	sin.sin_addr = *(struct in_addr *)e->host->h_addr;
	if ((connect(e->players[e->nb_player].sock,
		(t_sockaddr *)&sin, sizeof(sin))) == -1)
		return (-4);
	e->players[e->nb_player].status = 1;
	e->players[e->nb_player].type = FD_PLAYER;
	e->players[e->nb_player].level = 1;
	return (1);
}

static void			st_check_fd(t_env *e)
{
	int			i;

	i = 0;
	while (i < MAX_PLAYER)
	{
		if (e->players[i].type == FD_PLAYER
			&& FD_ISSET(e->players[i].sock, &e->fd_read))
			ft_read(&e->players[i], e);
		i++;
	}
}

void				ft_check_select(t_env *e)
{
	while (1)
	{
		if (e->graph.status == 2)
			break ;
		if (e->order_connect > 0)
		{
			if (ft_connect_serveur(e) > 0)
			{
				e->graph.modif = 0;
				while (e->players[e->nb_player].status < 5)
					if (!ft_read(&e->players[e->nb_player], e))
						break ;
				if (e->players[e->nb_player].status == 5)
				{
					e->nb_player++;
					e->connect--;
				}
			}
			e->order_connect--;
		}
		ft_check_action(e);
		select(e->max_fd + 1, &e->fd_read, NULL, NULL, NULL);
		st_check_fd(e);
	}
}
