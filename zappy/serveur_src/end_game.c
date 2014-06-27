/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 13:17:04 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 13:57:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdio.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

void	end_game(t_env *e, t_clients *player)
{
	char	tmp[BUF_SIZE];
	int		i;

	sprintf(tmp, "team %s win\n", player->name);
	i = -1;
	while (++i <= e->max_fd)
	{
		if (TYPE(i) == CLIENT_CLIENT || TYPE(i) == CLIENT_GRAPH)
		{
			ft_putstr_fd(tmp, i);
			close(i);
		}
		if (e->clients[i].type == CLIENT_SERV)
			close(i);
	}
	printf("team %s WIN!!!!!!!\n", player->name);
	exit(0);
}
