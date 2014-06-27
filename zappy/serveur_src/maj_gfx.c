/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maj_gfx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 14:53:48 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/13 16:05:48 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	maj_gfx(t_env *e, char *maj)
{
	int		i;

	i = 0;
	while (i <= e->max_fd)
	{
		if (e->clients[i].type == CLIENT_GRAPH)
			ft_strcat(e->clients[i].buf_write, maj);
		i++;
	}
}
