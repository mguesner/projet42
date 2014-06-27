/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_human.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:25:04 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:25:05 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void		ft_print_img(t_env *e, void *img, int x, int y)
{
	mlx_put_image_to_window(e->graph.mlx, e->graph.win,
	img, x, y);
}

void		ft_check_action_mlx(t_player *player, char *cmd, t_env *e)
{
	pthread_mutex_lock(&player->mutex);
	if (!player->cur_action)
	{
		player->cur_action = cmd;
		dprintf(player->sock, "%s", player->cur_action);
		printf("current : %s", player->cur_action);
		ft_print_img_cmd(e, player);
	}
	else if (player->nb_action < 10)
	{
		printf("%d\n", player->nb_action);
		player->action[player->nb_action] = cmd;
		player->nb_action++;
		ft_print_img_cmd(e, player);
	}
	else
		printf("file d'attente action full\n");
	pthread_mutex_unlock(&player->mutex);
}

int			expose(t_env *e)
{
	mlx_clear_window (e->graph.mlx, e->graph.win);
	ft_put_img_human(e);
	ft_print_img_players(e);
	ft_print_img_cmd(e, e->cur_player);
	if (e->cur_player && e->cur_player->inventory.status == 1)
		ft_print_img_inventory(e, e->cur_player);
	e->graph.modif = 1;
	return (0);
}

int			expose_loop(t_env *e)
{
	if (e->graph.modif == 0)
		return (expose(e));
	return (0);
}

void		*ft_mlx(void *p_data)
{
	t_env	*e;

	e = (t_env *)p_data;
	e->graph.mlx = mlx_init();
	if (e->graph.mlx != NULL)
		e->graph.win = mlx_new_window(e->graph.mlx, WIN_SIZE_X,
										WIN_SIZE_Y, TITLE);
	if (e->graph.mlx && e->graph.win)
	{
		ft_init_img(e);
		e->graph.status = 1;
		mlx_expose_hook(e->graph.win, &expose, e);
		mlx_loop_hook(e->graph.mlx, &expose_loop, e);
		mlx_do_key_autorepeaton(e->graph.mlx);
		mlx_hook(e->graph.win, 2, (1L << 0), ft_button, e);
		mlx_loop(e->graph.mlx);
	}
	return (NULL);
}
