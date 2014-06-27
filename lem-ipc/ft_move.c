/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 16:18:30 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 15:47:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	ft_move(char *map, int x[2], int team)
{
	map[x[0] * SIZE + x[1]] = '.';
	if (x[0] > SIZE / 2 && map[(x[0] - 1) * SIZE + x[1]] == '.')
		x[0] = x[0] - 1;
	else if (x[0] < SIZE / 2 && map[(x[0] + 1) * SIZE + x[1]] == '.')
		x[0] = x[0] + 1;
	else if (x[1] > SIZE / 2 && map[x[0] * SIZE + x[1] - 1] == '.')
		x[1] = x[1] - 1;
	else if (x[1] < SIZE / 2 && map[x[0] * SIZE + x[1] + 1] == '.')
		x[1] = x[1] + 1;
	else if (x[0] >= SIZE / 2 && map[(x[0] - 1) * SIZE + x[1]] == '.')
		x[0] = x[0] - 1;
	else if (x[0] <= SIZE / 2 && map[(x[0] + 1) * SIZE + x[1]] == '.')
		x[0] = x[0] + 1;
	else if (x[1] >= SIZE / 2 && map[x[0] * SIZE + x[1] - 1] == '.')
		x[1] = x[1] - 1;
	else if (x[1] <= SIZE / 2 && map[x[0] * SIZE + x[1] + 1] == '.')
		x[1] = x[1] + 1;
	map[x[0] * SIZE + x[1]] = team + '0';
}
