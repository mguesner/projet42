/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 13:21:20 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/09 15:03:07 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	prefork(t_env *e, int fd, char cmd[])
{
	e->clients[fd].fct_action[e->clients[fd].i_action] = pond;
	e->clients[fd].action[e->clients[fd].i_action] = 42;
	ft_strcpy(e->clients[fd].arg[e->clients[fd].i_action], cmd);
	e->clients[fd].i_action++;
}
