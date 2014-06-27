/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 15:43:39 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/21 09:55:53 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <unistd.h>
#include <stdio.h>
#include <libft.h>

void	ft_read(t_env *e, int fd)
{
	int		ret;
	int		i;

	if ((ret = read(fd, e->clients[fd].buf_read, BUF_SIZE)) <= 0)
	{
		if (e->clients[fd].type == CLIENT_CLIENT)
		{
			explode_player(e, &e->clients[fd]);
			e->map[e->clients[fd].Y][e->clients[fd].X].joueur--;
		}
		ft_strdel(&e->clients[fd].name);
		cleanclient(&e->clients[fd]);
		close(fd);
	}
	else
	{
		i = 0;
		while (i < ret && (i - 1 > 0 || e->clients[fd].buf_read[i - 1] != '\n'))
		{
			e->clients[fd].cbuf[e->clients[fd]
.end] = e->clients[fd].buf_read[i++];
			e->clients[fd].end = (e->clients[fd].end + 1) % BUF_SIZE;
		}
	}
	ft_strclr(e->clients[fd].buf_read);
}
