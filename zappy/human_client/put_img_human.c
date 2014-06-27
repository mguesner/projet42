/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_human.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:26:58 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:29:43 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void st_put_img_view(t_env *e, t_case *field, int x, int y)
{
	ft_print_img(e, FIELD_VOID.ptr, x, y);
	if (field->l)
		ft_print_img(e, OBJ_V_L.ptr, x + 5, y + 40);
	if (field->d)
		ft_print_img(e, OBJ_V_D.ptr, x + 70, y + 4);
	if (field->s)
		ft_print_img(e, OBJ_V_S.ptr, x + 70, y + 35);
	if (field->m)
		ft_print_img(e, OBJ_V_M.ptr, x + 5, y + 75);
	if (field->p)
		ft_print_img(e, OBJ_V_P.ptr, x + 70, y + 70);
	if (field->t)
		ft_print_img(e, OBJ_V_T.ptr, x + 4, y);
	if (field->food)
		ft_print_img(e, OBJ_V_FOOD.ptr, x + 40, y + 72);
	if (field->my_player)
		ft_print_img_my_player_view(e, field, x, y);
	if (field->other_player)
		ft_print_img(e, OBJ_V_OTHER.ptr, x + 40, y + 0);
}

static void st_put_img_fog(t_env *e, t_case *field, int x, int y)
{
	ft_print_img(e, FIELD_FOG.ptr, x, y);
	if (field->l)
		ft_print_img(e, OBJ_FOG_L.ptr, x + 5, y + 40);
	if (field->d)
		ft_print_img(e, OBJ_FOG_D.ptr, x + 70, y + 4);
	if (field->s)
		ft_print_img(e, OBJ_FOG_S.ptr, x + 70, y + 35);
	if (field->m)
		ft_print_img(e, OBJ_FOG_M.ptr, x + 5, y + 75);
	if (field->p)
		ft_print_img(e, OBJ_FOG_P.ptr, x + 70, y + 70);
	if (field->t)
		ft_print_img(e, OBJ_FOG_T.ptr, x + 4, y);
	if (field->food)
		ft_print_img(e, OBJ_FOG_FOOD.ptr, x + 40, y + 72);
	if (field->my_player)
		ft_print_img_my_player_fog(e, field, x, y);
}

static void	st_print_img_x(t_env *e, int y[2], int x[2], int start[2])
{
	while (x[1] < WIN_SIZE_X)
	{
		if (e->map[y[0]][x[0]].view == VISIBLE)
			st_put_img_view(e, &e->map[y[0]][x[0]], x[1], y[1]);
		else if (e->map[y[0]][x[0]].view == BROUILLARD)
			st_put_img_fog(e, &e->map[y[0]][x[0]], x[1], y[1]);
		x[1] += 100;
		ft_check_coor_x(&x[0], e, 1);
		if (x[0] == start[0])
			break ;
	}
}

void		ft_put_img_human(t_env *e)
{
	int		y[2];
	int		x[2];
	int		start[2];

	x[0] = e->view.case_x;
	y[0] = e->view.case_y;
	start[0] = x[0];
	start[1] = y[0];
	y[1] = e->graph.start_y;
	while (y[1] < (WIN_SIZE_Y))
	{
		x[1] = e->graph.start_x;
		st_print_img_x(e, y, x, start);
		y[1] += 100;
		ft_check_coor_y(&y[0], e, 1);
		if (y[0] == start[1])
			break ;
	}
}
