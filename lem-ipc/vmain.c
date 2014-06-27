/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/31 15:19:59 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 16:54:40 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <sys/shm.h>
#include <curses.h>

int		main(void)
{
	int		mem_id;
	char	*map;

	if ((mem_id = shmget(ftok("lemipc.h", 'k'), SIZE * SIZE, 0666)) < 0)
		ft_perror("shmget");
	if ((map = (char *)shmat(mem_id, NULL, 0)) == (void *)-1)
		ft_perror("shmat");
	ft_init();
	while (1)
		if (!ft_refresh(map))
			break ;
	endwin();
	curs_set(1);
	return (0);
}
