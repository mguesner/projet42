/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:50:33 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:50:34 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void		st_print_img_poser(t_env *e, char *cmd, int x, int y)
{
	if (!strcmp(cmd, POSER_FOOD))
		ft_print_img(e, BUTTON_POSER_F.ptr, x, y);
	else if (!strcmp(cmd, POSER_L))
		ft_print_img(e, BUTTON_POSER_L.ptr, x, y);
	else if (!strcmp(cmd, POSER_D))
		ft_print_img(e, BUTTON_POSER_D.ptr, x, y);
	else if (!strcmp(cmd, POSER_S))
		ft_print_img(e, BUTTON_POSER_S.ptr, x, y);
	else if (!strcmp(cmd, POSER_M))
		ft_print_img(e, BUTTON_POSER_M.ptr, x, y);
	else if (!strcmp(cmd, POSER_P))
		ft_print_img(e, BUTTON_POSER_P.ptr, x, y);
	else if (!strcmp(cmd, POSER_T))
		ft_print_img(e, BUTTON_POSER_T.ptr, x, y);
}

static void		st_print_img_prendre(t_env *e, char *cmd, int x, int y)
{
	if (!strcmp(cmd, PRENDRE_FOOD))
		ft_print_img(e, BUTTON_PRENDRE_F.ptr, x, y);
	else if (!strcmp(cmd, PRENDRE_L))
		ft_print_img(e, BUTTON_PRENDRE_L.ptr, x, y);
	else if (!strcmp(cmd, PRENDRE_D))
		ft_print_img(e, BUTTON_PRENDRE_D.ptr, x, y);
	else if (!strcmp(cmd, PRENDRE_S))
		ft_print_img(e, BUTTON_PRENDRE_S.ptr, x, y);
	else if (!strcmp(cmd, PRENDRE_M))
		ft_print_img(e, BUTTON_PRENDRE_M.ptr, x, y);
	else if (!strcmp(cmd, PRENDRE_P))
		ft_print_img(e, BUTTON_PRENDRE_P.ptr, x, y);
	else if (!strcmp(cmd, PRENDRE_T))
		ft_print_img(e, BUTTON_PRENDRE_T.ptr, x, y);
}

static void		st_print_img(t_env *e, char *cmd, int x, int y)
{
	if (!strcmp(cmd, AVANCE))
		ft_print_img(e, BUTTON_AVANCE.ptr, x, y);
	else if (!strcmp(cmd, DROITE))
		ft_print_img(e, BUTTON_DROITE.ptr, x, y);
	else if (!strcmp(cmd, GAUCHE))
		ft_print_img(e, BUTTON_GAUCHE.ptr, x, y);
	else if (!strcmp(cmd, VOIR))
		ft_print_img(e, BUTTON_VOIR.ptr, x, y);
	else if (!strcmp(cmd, INVENTAIRE))
		ft_print_img(e, BUTTON_INVENTAIRE.ptr, x, y);
	else if (!strcmp(cmd, EXPULSE))
		ft_print_img(e, BUTTON_EXPULSE.ptr, x, y);
	else if (!strcmp(cmd, FORK))
		ft_print_img(e, BUTTON_FORK.ptr, x, y);
	else if (!strcmp(cmd, INCANT))
		ft_print_img(e, BUTTON_LEVEL_UP.ptr, x, y);
	else if (!strncmp(cmd, "prend ", 6))
		st_print_img_prendre(e, cmd, x, y);
	else if (!strncmp(cmd, "pose ", 5))
		st_print_img_poser(e, cmd, x, y);
}

static void		st_print_list_cmd(t_env *e, t_player *player)
{
	int			i;

	i = 0;
	ft_print_img(e, OBJ_ACTION_LIST.ptr, (WIN_SIZE_X / 2) - 500,
					WIN_SIZE_Y - 100);
	while (i < player->nb_action)
	{
		st_print_img(e, player->action[i],
		(WIN_SIZE_X / 2) - 500 + 12 + 100 * i, WIN_SIZE_Y - 100 + 12);
		i++;
	}
}

void			ft_print_img_cmd(t_env *e, t_player *player)
{
	ft_print_img(e, OBJ_CUR_ACTION.ptr, (WIN_SIZE_X - 75) / 2 - 12,
					WIN_SIZE_Y - 200);
	if (player)
	{
		if (player->cur_action != NULL)
			st_print_img(e, player->cur_action, (WIN_SIZE_X - 75) / 2,
							WIN_SIZE_Y - 200 + 12);
		if (e->connect > 0)
			ft_print_img(e, BUTTON_CONNECT.ptr, (WIN_SIZE_X - 75) / 2 + 100,
						WIN_SIZE_Y - 200 + 12);
		st_print_list_cmd(e, player);
	}
}
