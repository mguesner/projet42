/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_void_me.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:23:28 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:23:29 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void			st_init_void_me_east(t_env *e)
{
	OBJ_VOID_EAST_CUR.ptr = ft_add_img(e, "textures/object/be1.xpm",
						&OBJ_VOID_EAST_CUR.width, &OBJ_VOID_EAST_CUR.height);
	OBJ_VOID_EAST_FREE.ptr = ft_add_img(e, "textures/object/be2.xpm",
						&OBJ_VOID_EAST_FREE.width, &OBJ_VOID_EAST_FREE.height);
	OBJ_VOID_EAST_OT.ptr = ft_add_img(e, "textures/object/be3.xpm",
						&OBJ_VOID_EAST_OT.width, &OBJ_VOID_EAST_OT.height);
}

static void			st_init_void_me_west(t_env *e)
{
	OBJ_VOID_WEST_CUR.ptr = ft_add_img(e, "textures/object/bo1.xpm",
						&OBJ_VOID_WEST_CUR.width, &OBJ_VOID_WEST_CUR.height);
	OBJ_VOID_WEST_FREE.ptr = ft_add_img(e, "textures/object/bo2.xpm",
						&OBJ_VOID_WEST_FREE.width, &OBJ_VOID_WEST_FREE.height);
	OBJ_VOID_WEST_OT.ptr = ft_add_img(e, "textures/object/bo3.xpm",
						&OBJ_VOID_WEST_OT.width, &OBJ_VOID_WEST_OT.height);
}

static void			st_init_void_me_north(t_env *e)
{
	OBJ_VOID_NORTH_CUR.ptr = ft_add_img(e, "textures/object/bn1.xpm",
						&OBJ_VOID_NORTH_CUR.width, &OBJ_VOID_NORTH_CUR.height);
	OBJ_VOID_NORTH_FREE.ptr = ft_add_img(e, "textures/object/bn2.xpm",
						&OBJ_VOID_NORTH_FREE.width,
						&OBJ_VOID_NORTH_FREE.height);
	OBJ_VOID_NORTH_OT.ptr = ft_add_img(e, "textures/object/bn3.xpm",
						&OBJ_VOID_NORTH_OT.width, &OBJ_VOID_NORTH_OT.height);
}

static void			st_init_void_me_south(t_env *e)
{
	OBJ_VOID_SOUTH_CUR.ptr = ft_add_img(e, "textures/object/bs1.xpm",
						&OBJ_VOID_SOUTH_CUR.width, &OBJ_VOID_SOUTH_CUR.height);
	OBJ_VOID_SOUTH_FREE.ptr = ft_add_img(e, "textures/object/bs2.xpm",
						&OBJ_VOID_SOUTH_FREE.width,
						&OBJ_VOID_SOUTH_FREE.height);
	OBJ_VOID_SOUTH_OT.ptr = ft_add_img(e, "textures/object/bs3.xpm",
						&OBJ_VOID_SOUTH_OT.width, &OBJ_VOID_SOUTH_OT.height);
}

void				ft_init_void_me(t_env *e)
{
	st_init_void_me_east(e);
	st_init_void_me_west(e);
	st_init_void_me_north(e);
	st_init_void_me_south(e);
}
