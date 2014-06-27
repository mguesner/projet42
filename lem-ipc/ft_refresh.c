/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 16:52:06 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 17:10:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "lemipc.h"

int	ft_refresh(char *map)
{
	int		i;
	int		pair;
	int		nb;

	i = 0;
	nb = 0;
	ft_legend();
	while (i < SIZE * SIZE)
	{
		if (map[i] != '.')
			nb++;
		pair = (map[i] != '.' ? map[i] - 48 : 0);
		attron(COLOR_PAIR(pair));
		mvprintw(i % SIZE + (LINES / 2) - (SIZE / 2), i / SIZE
			+ (COLS / 2) - (SIZE / 2), " ");
		attroff(COLOR_PAIR(pair));
		i++;
	}
	refresh();
	return (nb);
}
