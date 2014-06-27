/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_fog_me.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:22:20 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:22:22 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void			st_init_fog_me_east(t_env *e)
{
	OBJ_FOG_EAST_CUR.ptr = ft_add_img(e, "textures/object/bfe1.xpm",
						&OBJ_FOG_EAST_CUR.width, &OBJ_FOG_EAST_CUR.height);
	OBJ_FOG_EAST_FREE.ptr = ft_add_img(e, "textures/object/bfe2.xpm",
						&OBJ_FOG_EAST_FREE.width, &OBJ_FOG_EAST_FREE.height);
	OBJ_FOG_EAST_OT.ptr = ft_add_img(e, "textures/object/bfe3.xpm",
						&OBJ_FOG_EAST_OT.width, &OBJ_FOG_EAST_OT.height);
}

static void			st_init_fog_me_west(t_env *e)
{
	OBJ_FOG_WEST_CUR.ptr = ft_add_img(e, "textures/object/bfo1.xpm",
						&OBJ_FOG_WEST_CUR.width, &OBJ_FOG_WEST_CUR.height);
	OBJ_FOG_WEST_FREE.ptr = ft_add_img(e, "textures/object/bfo2.xpm",
						&OBJ_FOG_WEST_FREE.width, &OBJ_FOG_WEST_FREE.height);
	OBJ_FOG_WEST_OT.ptr = ft_add_img(e, "textures/object/bfo3.xpm",
						&OBJ_FOG_WEST_OT.width, &OBJ_FOG_WEST_OT.height);
}

static void			st_init_fog_me_north(t_env *e)
{
	OBJ_FOG_NORTH_CUR.ptr = ft_add_img(e, "textures/object/bfn1.xpm",
						&OBJ_FOG_NORTH_CUR.width, &OBJ_FOG_NORTH_CUR.height);
	OBJ_FOG_NORTH_FREE.ptr = ft_add_img(e, "textures/object/bfn2.xpm",
						&OBJ_FOG_NORTH_FREE.width, &OBJ_FOG_NORTH_FREE.height);
	OBJ_FOG_NORTH_OT.ptr = ft_add_img(e, "textures/object/bfn3.xpm",
						&OBJ_FOG_NORTH_OT.width, &OBJ_FOG_NORTH_OT.height);
}

static void			st_init_fog_me_south(t_env *e)
{
	OBJ_FOG_SOUTH_CUR.ptr = ft_add_img(e, "textures/object/bfs1.xpm",
						&OBJ_FOG_SOUTH_CUR.width, &OBJ_FOG_SOUTH_CUR.height);
	OBJ_FOG_SOUTH_FREE.ptr = ft_add_img(e, "textures/object/bfs2.xpm",
						&OBJ_FOG_SOUTH_FREE.width, &OBJ_FOG_SOUTH_FREE.height);
	OBJ_FOG_SOUTH_OT.ptr = ft_add_img(e, "textures/object/bfs3.xpm",
						&OBJ_FOG_SOUTH_OT.width, &OBJ_FOG_SOUTH_OT.height);
}

void				ft_init_fog_me(t_env *e)
{
	st_init_fog_me_east(e);
	st_init_fog_me_west(e);
	st_init_fog_me_north(e);
	st_init_fog_me_south(e);
}
