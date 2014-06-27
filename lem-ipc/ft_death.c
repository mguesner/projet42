/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 15:58:07 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 14:42:00 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <libft.h>
#include <stdlib.h>

void	ft_death(char *map, int x[2], int sem_id, int team)
{
	int		nb;
	int		i;
	int		tmp_x;
	int		tmp_y;

	i = 0;
	nb = 0;
	tmp_x = x[0] - 1;
	tmp_y = x[1] - 1;
	while (i < 9)
	{
		if (tmp_x + (i % 3) > 0 && tmp_x + (i % 3) < SIZE && tmp_y
			+ (i / 3) > 0 && tmp_y + (i / 3) < SIZE && map[(tmp_x + (i % 3))
				* SIZE + tmp_y + (i / 3)] != '.' && map[(tmp_x
					+ (i % 3)) * SIZE + tmp_y + (i / 3)] != team + '0')
			nb++;
		if (nb > 1)
		{
			map[x[0] * SIZE + x[1]] = '.';
			ft_unlock(sem_id);
			ft_printf("I'm dead X_x\n");
			exit(1);
		}
		i++;
	}
}
