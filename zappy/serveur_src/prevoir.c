/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prevoir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 12:52:09 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/18 13:33:18 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	prevoir(t_env *e, int fd, char cmd[])
{
	e->clients[fd].fct_action[e->clients[fd].i_action] = voir;
	e->clients[fd].action[e->clients[fd].i_action] = 7;
	ft_strcpy(e->clients[fd].arg[e->clients[fd].i_action], cmd);
	e->clients[fd].i_action++;
}
