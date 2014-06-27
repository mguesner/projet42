/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 15:54:11 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/08 17:35:51 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	loop(t_env *e)
{
	unsigned long	t;
	unsigned long	t2;
	unsigned long	t3;
	unsigned long	last_t;

	last_t = 0;
	while (1)
	{
		initclients(e);
		t2 = microtime();
		ft_select(e, t2, last_t);
		t3 = microtime();
		checkclients(e, t3, last_t);
		t = microtime();
		if (t - last_t >= (unsigned long)((1. / e->time) * 1000000))
			last_t = t;
	}
}
