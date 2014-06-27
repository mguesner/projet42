/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 16:33:17 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 16:44:09 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>

void	ft_init(void)
{
	initscr();
	raw();
	start_color();
	init_pair(0, 0, 0);
	init_pair(1, 1, 1);
	init_pair(2, 2, 2);
	init_pair(3, 3, 3);
	init_pair(4, 4, 4);
	init_pair(5, 5, 5);
	init_pair(6, 6, 6);
	init_pair(7, 7, 7);
	curs_set(0);
	noecho();
}
