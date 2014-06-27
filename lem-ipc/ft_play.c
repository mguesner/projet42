/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 15:36:56 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 16:32:51 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <libft.h>
#include <unistd.h>

void	ft_play(int x[2], int team, char *map, int sem_id)
{
	while (1)
	{
		ft_lock(sem_id);
		ft_putmap(map);
		if (ft_alone(map, team, x, sem_id))
			break ;
		ft_death(map, x, sem_id, team);
		ft_move(map, x, team);
		ft_putmap(map);
		ft_unlock(sem_id);
		sleep(1);
	}
}
