/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:22:32 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:22:35 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void				ft_init_view_object(t_env *e)
{
	OBJ_V_T.ptr = ft_add_img(e, "textures/object/vt.xpm",
				&OBJ_V_T.width, &OBJ_V_T.height);
	OBJ_V_L.ptr = ft_add_img(e, "textures/object/vl.xpm",
				&OBJ_V_L.width, &OBJ_V_L.height);
	OBJ_V_M.ptr = ft_add_img(e, "textures/object/vm.xpm",
				&OBJ_V_L.width, &OBJ_V_L.height);
	OBJ_V_FOOD.ptr = ft_add_img(e, "textures/object/vf.xpm",
					&OBJ_V_FOOD.width, &OBJ_V_FOOD.height);
	OBJ_V_P.ptr = ft_add_img(e, "textures/object/vp.xpm",
				&OBJ_V_T.width, &OBJ_V_P.height);
	OBJ_V_S.ptr = ft_add_img(e, "textures/object/vs.xpm",
				&OBJ_V_L.width, &OBJ_V_S.height);
	OBJ_V_D.ptr = ft_add_img(e, "textures/object/vd.xpm",
				&OBJ_V_L.width, &OBJ_V_D.height);
}

void				ft_init_fog_object(t_env *e)
{
	OBJ_FOG_T.ptr = ft_add_img(e, "textures/object/bft.xpm",
				&OBJ_V_T.width, &OBJ_V_T.height);
	OBJ_FOG_L.ptr = ft_add_img(e, "textures/object/bfl.xpm",
				&OBJ_V_L.width, &OBJ_V_L.height);
	OBJ_FOG_M.ptr = ft_add_img(e, "textures/object/bfm.xpm",
				&OBJ_V_L.width, &OBJ_V_L.height);
	OBJ_FOG_FOOD.ptr = ft_add_img(e, "textures/object/bff.xpm",
					&OBJ_V_FOOD.width, &OBJ_V_FOOD.height);
	OBJ_FOG_P.ptr = ft_add_img(e, "textures/object/bfp.xpm",
				&OBJ_V_T.width, &OBJ_V_P.height);
	OBJ_FOG_S.ptr = ft_add_img(e, "textures/object/bfs.xpm",
				&OBJ_V_L.width, &OBJ_V_S.height);
	OBJ_FOG_D.ptr = ft_add_img(e, "textures/object/bfd.xpm",
				&OBJ_V_L.width, &OBJ_V_D.height);
}
