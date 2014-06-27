/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initclients.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 15:55:33 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/02 16:29:01 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	initclients(t_env *e)
{
	int	i;

	i = 0;
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	while (i <= e->max_fd)
	{
		if (e->clients[i].type != CLIENT_FREE)
		{
			FD_SET(i, &e->fd_read);
			if (ft_strlen(e->clients[i].buf_write) > 0)
				FD_SET(i, &e->fd_write);
			e->max = i;
		}
		i++;
	}
}
