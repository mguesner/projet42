/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:05:18 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 10:33:17 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <term.h>

static void	ft_arrow2(void)
{
	if (!ft_strncmp("\033[C", g_e.line, 3) && g_e.i < (int)BUFF)
	{
		ft_reset();
		if ((g_e.i + g_e.prompt + 1) % tgetnum("co") == 0)
		{
			tputs(tgetstr("do", NULL), 1, ft_putonterm);
			tputs(tgoto(tgetstr("LE", NULL), 0, CO), 1, ft_putonterm);
		}
		else
			tputs(tgetstr("nd", NULL), 1, ft_putonterm);
		g_e.i++;
	}
}

void		ft_arrow(void)
{
	if (!ft_strncmp("\033[D", g_e.line, 3) && g_e.i > 0)
	{
		ft_reset();
		if ((g_e.i + g_e.prompt) % tgetnum("co") == 0)
		{
			tputs(tgetstr("up", NULL), 1, ft_putonterm);
			tputs(tgoto(tgetstr("RI", NULL), 0, CO), 1, ft_putonterm);
		}
		else
			tputs(tgetstr("le", NULL), 1, ft_putonterm);
		g_e.i--;
	}
	ft_arrow2();
}
