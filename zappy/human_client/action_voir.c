/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_voir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:27:14 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:27:14 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void		st_del_accol(char *tab)
{
	int			size;

	size = strlen(tab);
	if (tab[size - 1] == '}')
		tab[size - 1] = '\0';
}

void			ft_action_voir(t_player *player, t_env *e)
{
	char		**tab;
	int			i;
	int			len;

	tab = ft_strsplit(&player->read[1], ',');
	i = 0;
	len = ft_tablen((void **)tab);
	printf("ref : %d %d fin\n", player->y, player->x);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		if ((i + 1) == len && tab[i])
			st_del_accol(tab[i]);
		ft_obj_case_view(player, tab[i], e, i);
		i++;
	}
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
