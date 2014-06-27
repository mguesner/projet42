/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 17:09:29 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 17:15:51 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

static void	ft_legend2(void)
{
	attron(COLOR_PAIR(6));
	printw(" ");
	attroff(COLOR_PAIR(6));
	printw(" : team 6\n");
	attron(COLOR_PAIR(7));
	printw(" ");
	attroff(COLOR_PAIR(7));
	printw(" : team 7\n");
}

void		ft_legend(void)
{
	attron(COLOR_PAIR(1));
	mvprintw(0, 0, " ");
	attroff(COLOR_PAIR(1));
	printw(" : team 1\n");
	attron(COLOR_PAIR(2));
	printw(" ");
	attroff(COLOR_PAIR(2));
	printw(" : team 2\n");
	attron(COLOR_PAIR(3));
	printw(" ");
	attroff(COLOR_PAIR(3));
	printw(" : team 3\n");
	attron(COLOR_PAIR(4));
	printw(" ");
	attroff(COLOR_PAIR(4));
	printw(" : team 4\n");
	attron(COLOR_PAIR(5));
	printw(" ");
	attroff(COLOR_PAIR(5));
	printw(" : team 5\n");
	ft_legend2();
}
