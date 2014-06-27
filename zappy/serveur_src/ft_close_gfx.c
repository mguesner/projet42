/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_gfx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 17:17:40 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/24 17:39:20 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <unistd.h>
#include <libft.h>

int		ft_close_gfx(int fd, t_env *e)
{
	write(fd, "too big\n\n\n\n\n", 12);
	close(fd);
	ft_strdel(&e->clients[fd].name);
	cleanclient(&e->clients[fd]);
	return (1);
}
