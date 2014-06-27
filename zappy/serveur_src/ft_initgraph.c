/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgraph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:43:34 by rporcher          #+#    #+#             */
/*   Updated: 2014/06/25 11:26:56 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"
#include <libft.h>

static void	nothin(void)
{
	return ;
}

static void	ft_initgraph2(t_env *e, int i, int fd)
{
	char	tmp[BUF_SIZE];

	sprintf(tmp, "connect %d %d %d %d %d %s\n"
		, e->clients[i].nb, e->clients[i].X, e->clients[i].Y
		, e->clients[i].orient, e->clients[i].lvl, e->clients[i].name);
	write(fd, tmp, ft_strlen(tmp));
	sprintf(tmp, "inv %d %d %d %d %d %d %d %d %s\n", e->clients[i].nb
		, e->clients[i].life, e->clients[i].linemate
		, e->clients[i].deraumere, e->clients[i].sibur, e->clients[i].mendiane
		, e->clients[i].phiras, e->clients[i].thystame, e->clients[i].name);
	write(fd, tmp, ft_strlen(tmp));
}

int			ft_initgraph(t_env *e, int fd)
{
	int		i;
	int		j;
	char	tmp[BUF_SIZE];

	e->clients[fd].type = CLIENT_GRAPH;
	e->clients[fd].fct_cmd = nothin;
	e->clients[fd].connected = 1;
	sprintf(tmp, "map %d %d\n", e->width, e->height);
	write(fd, tmp, ft_strlen(tmp));
	i = -1;
	while (++i < e->height && (j = -1))
		while (++j < e->width)
			contenue(e, i, j, fd);
	i = -1;
	while (++i <= e->max_fd)
	{
		if (e->clients[i].type == CLIENT_CLIENT)
			ft_initgraph2(e, i, fd);
	}
	return (1);
}
