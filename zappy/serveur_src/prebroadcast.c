/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prebroadcast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 15:55:43 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/13 16:50:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	prebroadcast(t_env *e, int fd, char *cmd)
{
	e->clients[fd].fct_action[e->clients[fd].i_action] = broadcast;
	e->clients[fd].action[e->clients[fd].i_action] = 7;
	ft_strcpy(e->clients[fd].arg[e->clients[fd].i_action], cmd);
	e->clients[fd].i_action++;
}
