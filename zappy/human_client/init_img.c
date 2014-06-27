/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:21:51 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:21:59 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void		st_init_field(t_env *e)
{
	FIELD_VOID.ptr = ft_add_img(e, "textures/field/field_void.xpm",
					&FIELD_VOID.width, &FIELD_VOID.height);
	FIELD_FOG.ptr = ft_add_img(e, "textures/field/field_fog.xpm",
					&FIELD_FOG.width, &FIELD_FOG.height);
	FIELD_BLACK.ptr = ft_add_img(e, "textures/field/field_black.xpm",
					&FIELD_BLACK.width, &FIELD_BLACK.height);
}

static void		st_init_img_action(t_env *e)
{
	OBJ_CUR_ACTION.ptr = ft_add_img(e, "textures/object/main-action.xpm",
					&OBJ_CUR_ACTION.width, &OBJ_CUR_ACTION.height);
	OBJ_ACTION_LIST.ptr = ft_add_img(e, "textures/object/barre-action.xpm",
					&OBJ_ACTION_LIST.width, &OBJ_ACTION_LIST.height);
}

void			ft_init_img(t_env *e)
{
	st_init_field(e);
	ft_init_view_me(e);
	ft_init_fog_me(e);
	ft_init_void_me(e);
	ft_init_fog_object(e);
	ft_init_view_object(e);
	ft_init_button(e);
	ft_init_img_player(e);
	ft_init_img_inv(e);
	st_init_img_action(e);
}
