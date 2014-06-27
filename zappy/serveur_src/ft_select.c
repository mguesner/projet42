/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 16:01:53 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/12 15:06:59 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "zappy.h"
#include <libft.h>
#include <unistd.h>

void	ft_select(t_env *e, unsigned long t, unsigned long last_t)
{
	struct timeval	timeout;

	if (!last_t)
	{
		timeout.tv_sec = (int)(1. / e->time);
		timeout.tv_usec = (int)(((1. / e->time) * 1000000)) % 1000000;
	}
	else
	{
		timeout.tv_sec = (int)((1. / e->time) * 1000000
			- (t - last_t)) / 1000000;
		timeout.tv_usec = ((int)((1. / e->time) * 1000000 - (t - last_t))
			> 0 ? (int)((1. / e->time) * 1000000 - (t - last_t)) % 1000000 : 0);
	}
	if ((e->ret = select(e->max + 1, &e->fd_read, &e->fd_write
		, NULL, &timeout)) == -1)
		ft_perror("select");
}
