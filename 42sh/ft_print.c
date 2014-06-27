/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 11:26:34 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 11:35:58 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <term.h>
#include "ft_sh.h"

static void	ft_print2(void)
{
	int		index;

	if (*g_e.line == 4)
		ft_exit(1);
	if (*g_e.line == 127 && g_e.i > 0)
	{
		ft_reset();
		if ((g_e.i + g_e.prompt) % tgetnum("co") == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putonterm);
			tputs(tgoto(tgetstr("RI", NULL), 0, CO), 1, ft_putonterm);
		}
		else
			tputs(tgetstr("le", NULL), 1, ft_putonterm);
		tputs(tgetstr("cd", NULL), 1, ft_putonterm);
		g_e.i--;
		ft_del_char(g_e.buff, g_e.i);
		tputs(&g_e.buff[g_e.i], 1, ft_putonterm);
		index = ft_strlen(g_e.buff) - g_e.i;
		while (index > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_putonterm);
			index--;
		}
	}
}

void		ft_print(void)
{
	int		index;

	if (ft_isprint(*g_e.line) && !g_e.line[1])
	{
		ft_reset();
		ft_add(g_e.buff, g_e.i++, *g_e.line, &g_e.size);
		write(1, g_e.line, 1);
		tputs(tgetstr("cd", NULL), 1, ft_putonterm);
		tputs(&g_e.buff[g_e.i], 1, ft_putonterm);
		if (((int)ft_strlen(g_e.buff) + g_e.prompt) % CO == 0)
		{
			tputs(tgetstr("do", NULL), 1, ft_putonterm);
			tputs(tgetstr("cr", NULL), 1, ft_putonterm);
		}
		index = ft_strlen(g_e.buff) - g_e.i;
		if (((int)ft_strlen(g_e.buff) + g_e.prompt - index) / CO
			!= ((int)BUFF + g_e.prompt) / CO && index != 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putonterm);
			tputs(tgoto(tgetstr("RI", NULL), 0, CO - index), 1, ft_putonterm);
		}
		else if (index != 0)
			tputs(tgoto(tgetstr("LE", NULL), 0, index), 1, ft_putonterm);
	}
	ft_print2();
}
