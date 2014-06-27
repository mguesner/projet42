/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:19:51 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:19:54 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

void			ft_change_camera(t_env *e, int x, int y)
{
	ft_check_coor_y(&e->view.case_y, e, y);
	ft_check_coor_x(&e->view.case_x, e, x);
	e->graph.modif = 0;
	expose_loop(e);
}
