/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_view_me.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:23:04 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:23:04 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void			st_init_view_me_east(t_env *e)
{
	OBJ_V_EAST_CUR.ptr = ft_add_img(e, "textures/object/ve1.xpm",
						&OBJ_V_EAST_CUR.width, &OBJ_V_EAST_CUR.height);
	OBJ_V_EAST_FREE.ptr = ft_add_img(e, "textures/object/ve2.xpm",
						&OBJ_V_EAST_FREE.width, &OBJ_V_EAST_FREE.height);
	OBJ_V_EAST_OT.ptr = ft_add_img(e, "textures/object/ve3.xpm",
						&OBJ_V_EAST_OT.width, &OBJ_V_EAST_OT.height);
}

static void			st_init_view_me_west(t_env *e)
{
	OBJ_V_WEST_CUR.ptr = ft_add_img(e, "textures/object/vo1.xpm",
						&OBJ_V_WEST_CUR.width, &OBJ_V_WEST_CUR.height);
	OBJ_V_WEST_FREE.ptr = ft_add_img(e, "textures/object/vo2.xpm",
						&OBJ_V_WEST_FREE.width, &OBJ_V_WEST_FREE.height);
	OBJ_V_WEST_OT.ptr = ft_add_img(e, "textures/object/vo3.xpm",
						&OBJ_V_WEST_OT.width, &OBJ_V_WEST_OT.height);
}

static void			st_init_view_me_north(t_env *e)
{
	OBJ_V_NORTH_CUR.ptr = ft_add_img(e, "textures/object/vn1.xpm",
						&OBJ_V_NORTH_CUR.width, &OBJ_V_NORTH_CUR.height);
	OBJ_V_NORTH_FREE.ptr = ft_add_img(e, "textures/object/vn2.xpm",
						&OBJ_V_NORTH_FREE.width, &OBJ_V_NORTH_FREE.height);
	OBJ_V_NORTH_OT.ptr = ft_add_img(e, "textures/object/vn3.xpm",
						&OBJ_V_NORTH_OT.width, &OBJ_V_NORTH_OT.height);
}

static void			st_init_view_me_south(t_env *e)
{
	OBJ_V_SOUTH_CUR.ptr = ft_add_img(e, "textures/object/vs1.xpm",
						&OBJ_V_SOUTH_CUR.width, &OBJ_V_SOUTH_CUR.height);
	OBJ_V_SOUTH_FREE.ptr = ft_add_img(e, "textures/object/vs2.xpm",
						&OBJ_V_SOUTH_FREE.width, &OBJ_V_SOUTH_FREE.height);
	OBJ_V_SOUTH_OT.ptr = ft_add_img(e, "textures/object/vs3.xpm",
						&OBJ_V_SOUTH_OT.width, &OBJ_V_SOUTH_OT.height);
}

void				ft_init_view_me(t_env *e)
{
	OBJ_V_OTHER.ptr = ft_add_img(e, "textures/object/va.xpm",
					&OBJ_V_OTHER.width, &OBJ_V_OTHER.height);
	st_init_view_me_east(e);
	st_init_view_me_west(e);
	st_init_view_me_north(e);
	st_init_view_me_south(e);
}
