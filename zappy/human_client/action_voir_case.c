/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_voir_case.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 20:27:24 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/25 20:27:25 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void	st_init_case(t_case *place)
{
	place->view = 0;
	place->food = 0;
	place->l = 0;
	place->d = 0;
	place->s = 0;
	place->m = 0;
	place->p = 0;
	place->t = 0;
	place->other_player = 0;
}

static void	st_check_voir(t_case *field, char **tab, int i, int *count)
{
	if (!strcmp("nourriture", tab[i]) && field->food < 255)
		field->food++;
	else if (!strcmp("linemate", tab[i]) && field->l < 255)
		field->l++;
	else if (!strcmp("deraumere", tab[i]) && field->d < 255)
		field->d++;
	else if (!strcmp("sibur", tab[i]) && field->s < 255)
		field->s++;
	else if (!strcmp("mendiane", tab[i]) && field->m < 255)
		field->m++;
	else if (!strcmp("phiras", tab[i]) && field->p < 255)
		field->p++;
	else if (!strcmp("thystame", tab[i]) && field->t < 255)
		field->t++;
	else if (!strcmp("joueur", tab[i]) && *count < 255)
		(*count)++;
}

static void	ft_save_obj_case(t_case *field, char **tab)
{
	int		i;
	int		count;

	st_init_case(field);
	field->view = VISIBLE;
	i = 0;
	count = 0;
	while (tab[i])
	{
		st_check_voir(field, tab, i, &count);
		i++;
	}
	if (count > field->my_player)
		field->other_player = count - field->my_player;
}

static void	st_calcul_coor(int ref, int *ptr_y, int *ptr_x)
{
	int			i;
	int			y;
	int			x;

	i = 0;
	y = 0;
	x = 0;
	while (i < ref)
	{
		if (i <= ref && x < y)
			x++;
		else
		{
			y++;
			x = 0 - y;
		}
		i++;
	}
	*ptr_x = x;
	*ptr_y = y;
	printf("control i : %d,  %d %d fin\n", i, y, x);
}

void		ft_obj_case_view(t_player *player, char *tab, t_env *e, int i)
{
	char	**tmp;
	int		x;
	int		y;
	int		tmp_x;
	int		tmp_y;

	x = 0;
	y = 0;
	tmp_x = player->x;
	tmp_y = player->y;
	tmp = ft_splitspace(tab);
	st_calcul_coor(i, &y, &x);
	if (player->view == 0 && ft_check_coor_y(&tmp_y, e, 0 - y))
		ft_check_coor_x(&tmp_x, e, 0 + x);
	else if (player->view == 1 && ft_check_coor_y(&tmp_y, e, 0 + x))
		ft_check_coor_x(&tmp_x, e, 0 + y);
	else if (player->view == 2 && ft_check_coor_y(&tmp_y, e, 0 + y))
		ft_check_coor_x(&tmp_x, e, 0 - x);
	else if (player->view == 3 && ft_check_coor_x(&tmp_x, e, 0 - y))
		ft_check_coor_y(&tmp_y, e, 0 - x);
	ft_save_obj_case(&e->map[tmp_y][tmp_x], tmp);
	printf("control i : %d,  %d %d fin\n", i, y, x);
	ft_delfulltab((void ***)&tmp);
}
