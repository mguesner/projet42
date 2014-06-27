/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preinventaire.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 14:25:59 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/09 14:59:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	preinventaire(t_env *e, int fd, char cmd[])
{
	e->clients[fd].fct_action[e->clients[fd].i_action] = inventaire;
	e->clients[fd].action[e->clients[fd].i_action] = 1;
	ft_strcpy(e->clients[fd].arg[e->clients[fd].i_action], cmd);
	e->clients[fd].i_action++;
}
