/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:22:49 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:22:52 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void			st_init_player_ot(t_env *e)
{
	OBJ_PLAYER_OT_1.ptr = ft_add_img(e, "textures/player/11.xpm",
							&OBJ_PLAYER_OT_1.width, &OBJ_PLAYER_OT_1.height);
	OBJ_PLAYER_OT_2.ptr = ft_add_img(e, "textures/player/12.xpm",
							&OBJ_PLAYER_OT_2.width, &OBJ_PLAYER_OT_2.height);
	OBJ_PLAYER_OT_3.ptr = ft_add_img(e, "textures/player/13.xpm",
							&OBJ_PLAYER_OT_3.width, &OBJ_PLAYER_OT_3.height);
	OBJ_PLAYER_OT_4.ptr = ft_add_img(e, "textures/player/14.xpm",
							&OBJ_PLAYER_OT_4.width, &OBJ_PLAYER_OT_4.height);
	OBJ_PLAYER_OT_5.ptr = ft_add_img(e, "textures/player/15.xpm",
							&OBJ_PLAYER_OT_5.width, &OBJ_PLAYER_OT_5.height);
	OBJ_PLAYER_OT_6.ptr = ft_add_img(e, "textures/player/16.xpm",
							&OBJ_PLAYER_OT_6.width, &OBJ_PLAYER_OT_6.height);
	OBJ_PLAYER_OT_7.ptr = ft_add_img(e, "textures/player/17.xpm",
							&OBJ_PLAYER_OT_7.width, &OBJ_PLAYER_OT_7.height);
	OBJ_PLAYER_OT_8.ptr = ft_add_img(e, "textures/player/18.xpm",
							&OBJ_PLAYER_OT_8.width, &OBJ_PLAYER_OT_8.height);
}

static void			st_init_player_free(t_env *e)
{
	OBJ_PLAYER_FREE_1.ptr = ft_add_img(e, "textures/player/21.xpm",
							&OBJ_PLAYER_FREE_1.width,
							&OBJ_PLAYER_FREE_1.height);
	OBJ_PLAYER_FREE_2.ptr = ft_add_img(e, "textures/player/22.xpm",
							&OBJ_PLAYER_FREE_2.width,
							&OBJ_PLAYER_FREE_2.height);
	OBJ_PLAYER_FREE_3.ptr = ft_add_img(e, "textures/player/23.xpm",
							&OBJ_PLAYER_FREE_3.width,
							&OBJ_PLAYER_FREE_3.height);
	OBJ_PLAYER_FREE_4.ptr = ft_add_img(e, "textures/player/24.xpm",
							&OBJ_PLAYER_FREE_4.width,
							&OBJ_PLAYER_FREE_4.height);
	OBJ_PLAYER_FREE_5.ptr = ft_add_img(e, "textures/player/25.xpm",
							&OBJ_PLAYER_FREE_5.width,
							&OBJ_PLAYER_FREE_5.height);
	OBJ_PLAYER_FREE_6.ptr = ft_add_img(e, "textures/player/26.xpm",
							&OBJ_PLAYER_FREE_6.width,
							&OBJ_PLAYER_FREE_6.height);
	OBJ_PLAYER_FREE_7.ptr = ft_add_img(e, "textures/player/27.xpm",
							&OBJ_PLAYER_FREE_7.width,
							&OBJ_PLAYER_FREE_7.height);
	OBJ_PLAYER_FREE_8.ptr = ft_add_img(e, "textures/player/28.xpm",
							&OBJ_PLAYER_FREE_8.width,
							&OBJ_PLAYER_FREE_8.height);
}

static void			st_init_player_cur(t_env *e)
{
	OBJ_PLAYER_CUR_1.ptr = ft_add_img(e, "textures/player/31.xpm",
							&OBJ_PLAYER_CUR_1.width, &OBJ_PLAYER_CUR_1.height);
	OBJ_PLAYER_CUR_2.ptr = ft_add_img(e, "textures/player/32.xpm",
							&OBJ_PLAYER_CUR_2.width, &OBJ_PLAYER_CUR_2.height);
	OBJ_PLAYER_CUR_3.ptr = ft_add_img(e, "textures/player/33.xpm",
							&OBJ_PLAYER_CUR_3.width, &OBJ_PLAYER_CUR_3.height);
	OBJ_PLAYER_CUR_4.ptr = ft_add_img(e, "textures/player/34.xpm",
							&OBJ_PLAYER_CUR_4.width, &OBJ_PLAYER_CUR_4.height);
	OBJ_PLAYER_CUR_5.ptr = ft_add_img(e, "textures/player/35.xpm",
							&OBJ_PLAYER_CUR_5.width, &OBJ_PLAYER_CUR_5.height);
	OBJ_PLAYER_CUR_6.ptr = ft_add_img(e, "textures/player/36.xpm",
							&OBJ_PLAYER_CUR_6.width, &OBJ_PLAYER_CUR_6.height);
	OBJ_PLAYER_CUR_7.ptr = ft_add_img(e, "textures/player/37.xpm",
							&OBJ_PLAYER_CUR_7.width, &OBJ_PLAYER_CUR_7.height);
	OBJ_PLAYER_CUR_8.ptr = ft_add_img(e, "textures/player/38.xpm",
							&OBJ_PLAYER_CUR_8.width, &OBJ_PLAYER_CUR_8.height);
}

void				ft_init_img_player(t_env *e)
{
	st_init_player_ot(e);
	st_init_player_cur(e);
	st_init_player_free(e);
	OBJ_PLAYER_CUR_B.ptr = ft_add_img(e, "textures/player/39.xpm",
							&OBJ_PLAYER_CUR_B.width, &OBJ_PLAYER_CUR_B.height);
	OBJ_PLAYER_B.ptr = ft_add_img(e, "textures/player/19.xpm",
							&OBJ_PLAYER_B.width, &OBJ_PLAYER_B.height);
}
