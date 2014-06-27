/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preexpulse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 13:31:41 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/12 16:08:37 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	preexpulse(t_env *e, int fd, char *cmd)
{
	ft_printf("preexpulse\n");
	e->clients[fd].fct_action[e->clients[fd].i_action] = expulse;
	e->clients[fd].action[e->clients[fd].i_action] = 7;
	ft_strcpy(e->clients[fd].arg[e->clients[fd].i_action], cmd);
	e->clients[fd].i_action++;
}
