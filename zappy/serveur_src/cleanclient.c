/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanclient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 15:38:28 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/24 17:38:24 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	cleanclient(t_clients *client)
{
	client->type = CLIENT_FREE;
	client->start = 0;
	client->end = 0;
	client->connected = 0;
	client->name = NULL;
	client->fct_read = NULL;
	client->fct_write = NULL;
	client->fct_cmd = NULL;
	client->life = 0;
	client->linemate = 0;
	client->deraumere = 0;
	client->sibur = 0;
	client->mendiane = 0;
	client->phiras = 0;
	client->thystame = 0;
	bzero(client->buf_read, BUF_SIZE + 1);
	bzero(client->buf_write, BUF_SIZE + 1);
	bzero(client->cbuf, BUF_SIZE + 1);
	strcat(client->buf_write, "BIENVENUE\n");
	client->X = 0;
	client->Y = 0;
	client->orient = 0;
	client->lvl = 0;
}
