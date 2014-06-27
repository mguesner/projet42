/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hystor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:49:56 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 10:36:27 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <term.h>

static void	ft_hystor2(void)
{
	int		up;

	up = 0;
	if (!ft_strncmp("\033[B", g_e.line, 3) && g_e.hystor && g_e.hystor->next)
	{
		if ((up = (g_e.i + g_e.prompt - 1) / CO) > 0)
			tputs(tgoto(tgetstr("UP", NULL), 0, up), 1, ft_putonterm);
		tputs(tgetstr("cr", NULL), 1, ft_putonterm);
		tputs(tgetstr("cd", NULL), 1, ft_putonterm);
		tputs(tgetstr("up", NULL), 1, ft_putonterm);
		g_e.hystor = g_e.hystor->next;
		ft_reput_prompt(0);
		ft_putstr(g_e.hystor->content);
		ft_strcpy(g_e.buff, g_e.hystor->content);
		g_e.i = ft_strlen(g_e.buff);
	}
}

void		ft_hystor(void)
{
	int		up;

	up = 0;
	if (!ft_strncmp("\033[A", g_e.line, 3) && g_e.hystor)
	{
		if (g_e.hystor->flag != 1 && !g_e.hystor->next)
			ft_add_hystor(1);
		if ((up = (g_e.i + g_e.prompt - 1) / CO) > 0)
			tputs(tgoto(tgetstr("UP", NULL), 0, up), 1, ft_putonterm);
		tputs(tgetstr("cr", NULL), 1, ft_putonterm);
		tputs(tgetstr("cd", NULL), 1, ft_putonterm);
		tputs(tgetstr("up", NULL), 1, ft_putonterm);
		ft_reput_prompt(0);
		if (g_e.hystor->pre)
			g_e.hystor = g_e.hystor->pre;
		ft_putstr(g_e.hystor->content);
		ft_strclr(g_e.buff);
		ft_strcpy(g_e.buff, g_e.hystor->content);
		g_e.i = ft_strlen(g_e.buff);
	}
	ft_hystor2();
}
