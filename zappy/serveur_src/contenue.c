/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contenue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/11 11:11:59 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 14:26:01 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdio.h>
#include <libft.h>
#include <unistd.h>

void	contenue2(t_env *e, int i, int j)
{
	char	tmp[4096];

	sprintf(tmp, "inside %d %d %d %d %d %d %d %d %d\n", j, i
		, e->map[i][j].nourriture, e->map[i][j].linemate
		, e->map[i][j].deraumere, e->map[i][j].sibur, e->map[i][j].mendiane
		, e->map[i][j].phiras, e->map[i][j].thystame);
	maj_gfx(e, tmp);
}

void	contenue(t_env *e, int i, int j, int fd)
{
	char	tmp[4096];

	sprintf(tmp, "inside %d %d %d %d %d %d %d %d %d\n", j, i
		, e->map[i][j].nourriture, e->map[i][j].linemate
		, e->map[i][j].deraumere, e->map[i][j].sibur, e->map[i][j].mendiane
		, e->map[i][j].phiras, e->map[i][j].thystame);
	write(fd, tmp, ft_strlen(tmp));
}
