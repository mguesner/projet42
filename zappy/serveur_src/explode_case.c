/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explode_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/17 11:44:20 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 14:31:35 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdlib.h>
#include <libft.h>

void	explode_case2(t_env *e, t_case *casee)
{
	int		x;
	int		y;

	while (casee->mendiane && casee->mendiane--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].mendiane++;
		contenue2(e, y, x);
	}
	while (casee->phiras && casee->phiras--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].phiras++;
		contenue2(e, y, x);
	}
	while (casee->thystame && casee->thystame--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].thystame++;
		contenue2(e, y, x);
	}
}

void	explode_case(t_env *e, t_case *casee)
{
	int		x;
	int		y;

	while (casee->linemate && casee->linemate--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].linemate++;
		contenue2(e, y, x);
	}
	while (casee->deraumere && casee->deraumere--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].deraumere++;
		contenue2(e, y, x);
	}
	while (casee->sibur && casee->sibur--)
	{
		y = rand() % e->height;
		x = rand() % e->width;
		e->map[y][x].sibur++;
		contenue2(e, y, x);
	}
	explode_case2(e, casee);
}
