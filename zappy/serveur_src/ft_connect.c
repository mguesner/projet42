/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 17:55:19 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 11:08:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static void		ft_connect2(t_env *e, int fd, t_list *tmp2)
{
	e->clients[fd].type = CLIENT_CLIENT;
	e->clients[fd].action[0] = 0;
	e->clients[fd].orient = rand() % 4;
	bzero(e->clients[fd].fct_action, 11 * sizeof(*(e->clients[fd].fct_action)));
	bzero(e->clients[fd].action, 11 * sizeof(*(e->clients[fd].action)));
	bzero(e->clients[fd].arg, 11 * sizeof(*(e->clients[fd].arg)));
	e->clients[fd].i_action = 0;
	e->map[e->clients[fd].Y][e->clients[fd].X].joueur++;
	e->clients[fd].connected = 1;
	e->clients[fd].lvl = 1;
	sprintf(e->clients[fd].buf_write + strlen(e->clients[fd].buf_write)
		, "%d\n%d %d\n", tmp2->nb_connect, e->width, e->height);
	tmp2->nb_connect--;
	connect_gfx(e, &e->clients[fd]);
}

static void		ft_connect3(t_env *e, int fd, t_list *tmp2, char *cmd)
{
	if (!isoeuf(e, &e->clients[fd], cmd))
	{
		e->clients[fd].Y = rand() % e->height;
		e->clients[fd].X = rand() % e->width;
		e->clients[fd].life = 1260;
		e->clients[fd].nb = tmp2->nb_player++;
	}
	ft_connect2(e, fd, tmp2);
	if (strncmp(cmd, "_inter_", 7) == 0)
		sprintf(e->clients[fd].buf_write + strlen(e->clients[fd].buf_write)
			, "%d\n", e->clients[fd].orient);
}

void			ft_connect(t_env *e, int fd, char *cmd)
{
	t_list	*tmp2;

	if (strncmp(cmd, "_inter_", 7) == 0)
		e->clients[fd].name = ft_strdup(strchr(cmd, ' ') + 1);
	else
		e->clients[fd].name = ft_strdup(cmd);
	ft_printf("%s est arrive\n", e->clients[fd].name);
	if (strcmp(cmd, "__GFX__") == 0 && ft_initgraph(e, fd))
		return ;
	tmp2 = e->names;
	while (tmp2)
	{
		if (!strcmp(e->clients[fd].name, tmp2->name) && tmp2->nb_connect > 0)
		{
			ft_connect3(e, fd, tmp2, cmd);
			return ;
		}
		tmp2 = tmp2->next;
	}
	close(fd);
	ft_strdel(&e->clients[fd].name);
	cleanclient(&e->clients[fd]);
}
