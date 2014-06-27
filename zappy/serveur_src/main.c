/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 14:09:41 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/14 14:52:27 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdio.h>
#include <netdb.h>
#include <libft.h>
#include <stdlib.h>
#include <time.h>

void	serveur(t_env *e)
{
	t_protoent		*prot;
	t_sockaddr_in	sin;
	int				sock;

	if (!(prot = getprotobyname("tcp")))
		ft_error("getprotobyname");
	if ((sock = socket(PF_INET, SOCK_STREAM, prot->p_proto)) == -1)
		ft_perror("socket");
	sin.sin_family = AF_INET;
	if (e->port < 1)
		ft_error("bad port");
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(e->port);
	if (bind(sock, (t_sockaddr*)&sin, sizeof(sin)) == -1)
		ft_perror("bind");
	if (listen(sock, 5) == -1)
		ft_perror("listen");
	e->max_fd = sock;
	e->clients[sock].type = CLIENT_SERV;
	e->clients[sock].fct_read = ft_accept;
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc >= 13 && opt(argv, &e))
	{
		srand(time(NULL));
		initenv(&e);
		serveur(&e);
		loop(&e);
	}
	else
	{
		fprintf(stderr, "Usage: ./serveur -p <port> -x <width> -y <height> -n");
		fprintf(stderr, " <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
		fprintf(stderr, "\t-p numero de port\n");
		fprintf(stderr, "\t-x largeur du Monde\n");
		fprintf(stderr, "\t-y hauteur du Monde\n");
		fprintf(stderr, "\t-n nom_equipe_1 nom_equipe_2 ...\n");
		fprintf(stderr, "\t-c nombre de client autorises au commencement ");
		fprintf(stderr, "du jeu\n");
		fprintf(stderr, "\t-t diviseur de l'unite de temps (plus t est grand");
		fprintf(stderr, ", plus le jeu va vite)\n");
	}
	return (0);
}
