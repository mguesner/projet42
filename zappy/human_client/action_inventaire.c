/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_inventaire.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:26:43 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:26:44 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void				ft_init_inventaire(t_player *player)
{
	player->inventory.status = 0;
	player->inventory.food = 0;
	player->inventory.l = 0;
	player->inventory.d = 0;
	player->inventory.s = 0;
	player->inventory.m = 0;
	player->inventory.p = 0;
	player->inventory.t = 0;
}

static void			st_check_tab(t_player *player, char *tmp)
{
	char			*tab;

	tab = ft_strtrim(tmp);
	printf("%s\n", tab);
	if (!strncmp("linemate", tab, 8))
		player->inventory.l = atoi(&tab[9]);
	else if (!strncmp("deraumere", tab, 9))
		player->inventory.d = atoi(&tab[10]);
	else if (!strncmp("sibur", tab, 5))
		player->inventory.s = atoi(&tab[6]);
	else if (!strncmp("mendiane", tab, 8))
		player->inventory.m = atoi(&tab[9]);
	else if (!strncmp("phiras", tab, 6))
		player->inventory.p = atoi(&tab[7]);
	else if (!strncmp("thystame", tab, 8))
	{
		printf("inv t : %d\n", atoi(&tab[9]));
		player->inventory.t = atoi(&tab[9]);
	}
	else if (!strncmp("nourriture", tab, 10))
	{
		player->inventory.food = atoi(&tab[11]);
		printf("inv food : %d\n", atoi(&tab[11]));
	}
}

void				ft_action_inventaire(t_player *player, t_env *e)
{
	char		**tab;
	int			i;
	int			len;

	tab = ft_strsplit(player->read, ',');
	i = 0;
	len = ft_tablen((void **)tab);
	printf("ref : %d %d fin\n", player->y, player->x);
	while (tab[i])
	{
		st_check_tab(player, tab[i]);
		i++;
	}
	player->inventory.status = 1;
	player->cur_action = player->action[0];
	if (player->cur_action != NULL)
	{
		ft_destroy_action(player, 0);
		dprintf(player->sock, "%s", player->cur_action);
		printf("current : %s", player->cur_action);
	}
	ft_delfulltab((void ***)&tab);
	e->graph.modif = 0;
}
