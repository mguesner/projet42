/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 13:04:31 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/26 14:15:46 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

static void	inside2(t_clients *player, int *first, char *str)
{
	if ((*first) == 0)
	{
		ft_strcat(player->buf_write, " ");
	}
	ft_strcat(player->buf_write, str);
	(*first) = 0;
}

void		inside(t_clients *player, t_case place, int i)
{
	int		tmp;
	int		first;

	first = 1;
	tmp = place.joueur - i;
	while (tmp--)
		inside2(player, &first, "joueur");
	while (place.nourriture--)
		inside2(player, &first, "nourriture");
	while (place.linemate--)
		inside2(player, &first, "linemate");
	while (place.deraumere--)
		inside2(player, &first, "deraumere");
	while (place.sibur--)
		inside2(player, &first, "sibur");
	while (place.mendiane--)
		inside2(player, &first, "mendiane");
	while (place.phiras--)
		inside2(player, &first, "phiras");
	while (place.thystame--)
		inside2(player, &first, "thystame");
}
