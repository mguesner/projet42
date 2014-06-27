/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 15:19:35 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/13 17:34:37 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <libft.h>

void	ft_accept(t_env *e, int sock)
{
	int				csock;
	socklen_t		csin_len;
	t_sockaddr_in	csin;

	csin_len = sizeof(csin);
	if ((csock = accept(sock, (t_sockaddr *)&csin, &csin_len)) == -1)
		ft_perror("accept");
	cleanclient(&e->clients[csock]);
	e->max_fd = e->max_fd > csock ? e->max_fd : csock;
	e->clients[csock].type = CLIENT_ATT;
	e->clients[csock].fct_read = ft_read;
	e->clients[csock].fct_write = ft_write;
	e->clients[csock].fct_cmd = ft_cmd;
}
