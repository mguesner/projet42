/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/02 17:11:16 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/26 14:09:50 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>
#include <unistd.h>

static void		ft_cmd4(t_env *e, char cmd[], int fd)
{
	if (e->clients[fd].i_action < 10 && !ft_strcmp("fork", cmd))
		prefork(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("expulse", cmd))
		preexpulse(e, fd, cmd);
}

static void		ft_cmd3(t_env *e, char cmd[], int fd, char **tab)
{
	if (!e->clients[fd].connected)
		ft_connect(e, fd, cmd);
	else if (TEST && !ft_strcmp("prend", tab[0]) && tab[1])
		preprend(e, fd, cmd);
	else if (TEST && !ft_strcmp("pose", tab[0]) && tab[1])
		prepose(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("avance", cmd))
		preavance(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("droite", cmd))
		predroite(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("gauche", cmd))
		pregauche(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("voir", cmd))
		prevoir(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("inventaire", cmd))
		preinventaire(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("incantation", cmd))
		preincantation(e, fd, cmd);
	else if (e->clients[fd].i_action < 10 && !ft_strcmp("connect_nbr", cmd))
		connect_nbr(e, fd);
	else if (TEST && !ft_strcmp("broadcast", tab[0]) && tab[1])
		prebroadcast(e, fd, cmd);
	else
		ft_cmd4(e, cmd, fd);
}

static void		ft_cmd2(t_env *e, char cmd[], int fd)
{
	char	**tab;

	ft_strtrimbadass(cmd);
	ft_printf("__CMD : %s__ ->%d\n", cmd, e->clients[fd].nb);
	tab = ft_strsplit(cmd, ' ');
	ft_cmd3(e, cmd, fd, tab);
	ft_tabdel(&tab);
}

void			ft_cmd(t_env *e, int fd)
{
	char	cmd[BUF_SIZE + 1];
	int		i;

	bzero(cmd, BUF_SIZE + 1);
	while (e->clients[fd].cbuf[modulo((e->clients[fd].end - 1)
		, BUF_SIZE)] == '\n'
		&& e->clients[fd].end != e->clients[fd].start)
	{
		i = 0;
		while (e->clients[fd].cbuf[modulo((e->clients[fd].end - 1)
			, BUF_SIZE)] == '\n'
			&& e->clients[fd].cbuf[modulo(e->clients[fd].start
				, BUF_SIZE)] != '\n')
		{
			cmd[i++] = e->clients[fd].cbuf[e->clients[fd].start];
			e->clients[fd].start = (e->clients[fd].start + 1) % BUF_SIZE;
		}
		ft_cmd2(e, cmd, fd);
		ft_strclr(cmd);
		e->clients[fd].start = (e->clients[fd].start + 1) % BUF_SIZE;
	}
}
