/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_inv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 06:24:27 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/27 06:24:29 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void				ft_init_img_inv(t_env *e)
{
	OBJ_INV_VOID.ptr = ft_add_img(e, "textures/inventory/inv_void.xpm",
				&OBJ_INV_VOID.width, &OBJ_INV_VOID.height);
	OBJ_INV_BASE.ptr = ft_add_img(e, "textures/inventory/inventory.xpm",
				&OBJ_INV_BASE.width, &OBJ_INV_BASE.height);
	OBJ_INV_I0.ptr = ft_add_img(e, "textures/inventory/i0.xpm",
				&OBJ_INV_I0.width, &OBJ_INV_I0.height);
	OBJ_INV_I1.ptr = ft_add_img(e, "textures/inventory/i1.xpm",
				&OBJ_INV_I1.width, &OBJ_INV_I1.height);
	OBJ_INV_I2.ptr = ft_add_img(e, "textures/inventory/i2.xpm",
				&OBJ_INV_I2.width, &OBJ_INV_I2.height);
	OBJ_INV_I3.ptr = ft_add_img(e, "textures/inventory/i3.xpm",
				&OBJ_INV_I3.width, &OBJ_INV_I3.height);
	OBJ_INV_I4.ptr = ft_add_img(e, "textures/inventory/i4.xpm",
				&OBJ_INV_I4.width, &OBJ_INV_I4.height);
	OBJ_INV_I5.ptr = ft_add_img(e, "textures/inventory/i5.xpm",
				&OBJ_INV_I5.width, &OBJ_INV_I5.height);
	OBJ_INV_I6.ptr = ft_add_img(e, "textures/inventory/i6.xpm",
				&OBJ_INV_I6.width, &OBJ_INV_I6.height);
	OBJ_INV_IX.ptr = ft_add_img(e, "textures/inventory/ix.xpm",
				&OBJ_INV_IX.width, &OBJ_INV_IX.height);
}
