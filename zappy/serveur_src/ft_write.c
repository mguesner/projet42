/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 15:48:30 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 14:33:21 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <unistd.h>
#include <libft.h>
#include <stdio.h>

void	ft_write(t_env *e, int fd)
{
	ft_putstr_fd(e->clients[fd].buf_write, fd);
	ft_printf("__WRITE__ (%s, %d): %s -> %d__\n", e->clients[fd].name
		, e->clients[fd].nb
		, e->clients[fd].buf_write, e->clients[fd].orient);
	if (!ft_strcmp("mort\n", e->clients[fd].buf_write))
	{
		close(fd);
		(e->map[e->clients[fd].Y][e->clients[fd].X].joueur)--;
		ft_strdel(&e->clients[fd].name);
		cleanclient(&e->clients[fd]);
	}
	ft_strclr(e->clients[fd].buf_write);
}
