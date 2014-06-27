/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 14:01:13 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/29 18:51:08 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <stdlib.h>
#include <libft.h>
#include <time.h>
#include <unistd.h>

void	ft_initplay(int team, void *shared, int sem_id)
{
	char	*map;
	int		x[2];

	map = (char *)shared;
	srand(time(NULL));
	x[0] = rand() % SIZE;
	x[1] = rand() % SIZE;
	ft_printf("x : %d, y : %d\n", x[0], x[1]);
	ft_lock(sem_id);
	while (map[x[0] * SIZE + x[1]] != '.')
	{
		x[0] = rand() % SIZE;
		x[1] = rand() % SIZE;
	}
	map[x[0] * SIZE + x[1]] = team + '0';
	ft_unlock(sem_id);
	sleep(3);
	ft_putmap(map);
	ft_play(x, team, map, sem_id);
}
