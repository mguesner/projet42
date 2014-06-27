/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_view_tool_human.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:20:31 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:20:32 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

int				ft_check_coor_x(int *x, t_env *e, int i)
{
	*x += i;
	if (*x < 0)
		*x = e->x + *x;
	else if (*x >= e->x)
		*x = *x - e->x;
	return (1);
}

int				ft_check_coor_y(int *y, t_env *e, int i)
{
	*y += i;
	if (*y < 0)
		*y = e->y + *y;
	else if (*y >= e->y)
		*y = *y - e->y;
	return (1);
}

void			ft_check_view_case(t_env *e, int y, int x)
{
	if (y >= 0 && x >= 0)
	{
		if (e->map[y][x].view == VISIBLE)
			e->map[y][x].view = BROUILLARD;
	}
}
