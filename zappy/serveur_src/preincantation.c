/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preincantation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/06 14:54:09 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/20 17:19:11 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	preincantation(t_env *e, int fd, char cmd[])
{
	ft_printf("preincantation : %d\n", e->clients[fd].i_action);
	e->clients[fd].fct_action[e->clients[fd].i_action] = incantation;
	e->clients[fd].action[e->clients[fd].i_action] = 300;
	ft_strcpy(e->clients[fd].arg[e->clients[fd].i_action], cmd);
	e->clients[fd].i_action++;
	if (e->clients[fd].i_action == 1)
		ft_strcat(e->clients[fd].buf_write, "elevation en cours\n");
}
