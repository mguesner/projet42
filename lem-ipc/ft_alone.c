/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 15:53:34 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 16:51:21 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <libft.h>
#include <stdlib.h>

int		ft_alone(char *map, int team, int x[2], int sem_id)
{
	int		i;
	int		nb_tm;
	int		nb_player;

	i = -1;
	nb_tm = 0;
	nb_player = 0;
	while (++i < SIZE * SIZE)
	{
		nb_player = (map[i] != '.' ? nb_player + 1 : nb_player);
		nb_tm = (map[i] != '.' && map[i] != team + '0' ? nb_tm + 1 : nb_tm);
	}
	if (nb_tm == 0 && nb_player == 1)
	{
		map[x[0] * SIZE + x[1]] = '.';
		return (1);
	}
	else if (nb_tm == 0 && nb_player > 1)
	{
		map[x[0] * SIZE + x[1]] = '.';
		ft_unlock(sem_id);
		ft_printf("team %d win!\n", team);
		exit(1);
	}
	return (0);
}
