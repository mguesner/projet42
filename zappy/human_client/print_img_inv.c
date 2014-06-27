/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img_inv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/27 07:18:11 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/27 07:18:12 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static int		st_check_nb(int i)
{
	if (i > 6)
		return (7);
	return (i);
}

static void		st_check_obj(t_env *e, int *x, int *y, int s)
{
	int			tmp;
	t_img		*img;

	img = &OBJ_INV_I0;
	tmp = st_check_nb(s);
	ft_print_img(e, img[tmp].ptr, *x, *y);
	(*y) = *y + 67;
}

void			ft_print_img_inventory(t_env *e, t_player *player)
{
	int			i;
	int			place_x;
	int			place_y;

	i = 0;
	place_x = WIN_SIZE_X - 120;
	place_y = WIN_SIZE_Y - 820;
	ft_print_img(e, OBJ_INV_BASE.ptr, (WIN_SIZE_X - 450), (WIN_SIZE_Y - 900));
	st_check_obj(e, &place_x, &place_y, player->inventory.l);
	st_check_obj(e, &place_x, &place_y, player->inventory.d);
	st_check_obj(e, &place_x, &place_y, player->inventory.s);
	st_check_obj(e, &place_x, &place_y, player->inventory.m);
	st_check_obj(e, &place_x, &place_y, player->inventory.p);
	st_check_obj(e, &place_x, &place_y, player->inventory.t);
	st_check_obj(e, &place_x, &place_y, player->inventory.food);
}
