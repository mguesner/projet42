/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:28:09 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:28:10 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md.h"

void				ft_error(char *str, int ret)
{
	perror(str);
	exit(ret);
}

void				*ft_add_img(t_env *e, char *file, int *width, int *height)
{
	void			*tmp;

	tmp = mlx_xpm_file_to_image(e->graph.mlx, file, width, height);
	if (!tmp)
	{
		dprintf(2, "can't add file : %s\n", file);
		exit (-1);
	}
	return (tmp);
}

void				ft_action_ko(t_player *player, t_env *e)
{
	printf("echec %s\n", player->cur_action);
	player->cur_action = player->action[0];
	if (player->cur_action != NULL)
	{
		ft_destroy_action(player, 0);
		dprintf(player->sock, "%s", player->cur_action);
		printf("current : %s", player->cur_action);
	}
	e->graph.modif = 0;
}
