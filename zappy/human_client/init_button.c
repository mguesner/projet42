/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:21:42 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:21:43 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void		st_init_poser(t_env *e)
{
	BUTTON_POSER_D.ptr = ft_add_img(e, "textures/button/poser_d.xpm",
						&BUTTON_POSER_D.width, &BUTTON_POSER_D.height);
	BUTTON_POSER_F.ptr = ft_add_img(e, "textures/button/poser_f.xpm",
						&BUTTON_POSER_F.width, &BUTTON_POSER_F.height);
	BUTTON_POSER_L.ptr = ft_add_img(e, "textures/button/poser_l.xpm",
						&BUTTON_POSER_L.width, &BUTTON_POSER_L.height);
	BUTTON_POSER_M.ptr = ft_add_img(e, "textures/button/poser_m.xpm",
						&BUTTON_POSER_M.width, &BUTTON_POSER_M.height);
	BUTTON_POSER_P.ptr = ft_add_img(e, "textures/button/poser_p.xpm",
						&BUTTON_POSER_P.width, &BUTTON_POSER_P.height);
	BUTTON_POSER_S.ptr = ft_add_img(e, "textures/button/poser_s.xpm",
						&BUTTON_POSER_S.width, &BUTTON_POSER_S.height);
	BUTTON_POSER_T.ptr = ft_add_img(e, "textures/button/poser_t.xpm",
						&BUTTON_POSER_T.width, &BUTTON_POSER_T.height);
}

static void		st_init_prendre(t_env *e)
{
	BUTTON_PRENDRE_D.ptr = ft_add_img(e, "textures/button/prendre_d.xpm",
						&BUTTON_PRENDRE_D.width, &BUTTON_PRENDRE_D.height);
	BUTTON_PRENDRE_F.ptr = ft_add_img(e, "textures/button/prendre_f.xpm",
						&BUTTON_PRENDRE_F.width, &BUTTON_PRENDRE_F.height);
	BUTTON_PRENDRE_L.ptr = ft_add_img(e, "textures/button/prendre_l.xpm",
						&BUTTON_PRENDRE_L.width, &BUTTON_PRENDRE_L.height);
	BUTTON_PRENDRE_M.ptr = ft_add_img(e, "textures/button/prendre_m.xpm",
						&BUTTON_PRENDRE_M.width, &BUTTON_PRENDRE_M.height);
	BUTTON_PRENDRE_P.ptr = ft_add_img(e, "textures/button/prendre_p.xpm",
						&BUTTON_PRENDRE_P.width, &BUTTON_PRENDRE_P.height);
	BUTTON_PRENDRE_S.ptr = ft_add_img(e, "textures/button/prendre_s.xpm",
						&BUTTON_PRENDRE_S.width, &BUTTON_PRENDRE_S.height);
	BUTTON_PRENDRE_T.ptr = ft_add_img(e, "textures/button/prendre_t.xpm",
						&BUTTON_PRENDRE_T.width, &BUTTON_PRENDRE_T.height);
}

static void		st_init_move(t_env *e)
{
	BUTTON_AVANCE.ptr = ft_add_img(e, "textures/button/Avance.xpm",
						&BUTTON_AVANCE.width, &BUTTON_AVANCE.height);
	BUTTON_DROITE.ptr = ft_add_img(e, "textures/button/droite.xpm",
						&BUTTON_DROITE.width, &BUTTON_DROITE.height);
	BUTTON_GAUCHE.ptr = ft_add_img(e, "textures/button/gauche.xpm",
						&BUTTON_GAUCHE.width, &BUTTON_GAUCHE.height);
}

static void		st_init_div(t_env *e)
{
	BUTTON_BROAD.ptr = ft_add_img(e, "textures/button/broadcast.xpm",
						&BUTTON_BROAD.width, &BUTTON_BROAD.height);
	BUTTON_EXPULSE.ptr = ft_add_img(e, "textures/button/expulse.xpm",
						&BUTTON_EXPULSE.width, &BUTTON_EXPULSE.height);
	BUTTON_FORK.ptr = ft_add_img(e, "textures/button/fork.xpm",
						&BUTTON_FORK.width, &BUTTON_FORK.height);
	BUTTON_INVENTAIRE.ptr = ft_add_img(e, "textures/button/inventaire.xpm",
						&BUTTON_INVENTAIRE.width, &BUTTON_INVENTAIRE.height);
	BUTTON_LEVEL_UP.ptr = ft_add_img(e, "textures/button/level-up.xpm",
						&BUTTON_LEVEL_UP.width, &BUTTON_LEVEL_UP.height);
	BUTTON_VOIR.ptr = ft_add_img(e, "textures/button/voir.xpm",
						&BUTTON_VOIR.width, &BUTTON_VOIR.height);
	BUTTON_VIDE.ptr = ft_add_img(e, "textures/button/vide.xpm",
						&BUTTON_VIDE.width, &BUTTON_VIDE.height);
	BUTTON_CONNECT.ptr = ft_add_img(e, "textures/button/connect.xpm",
						&BUTTON_CONNECT.width, &BUTTON_CONNECT.height);
}

void			ft_init_button(t_env *e)
{
	st_init_move(e);
	st_init_poser(e);
	st_init_prendre(e);
	st_init_div(e);
}
