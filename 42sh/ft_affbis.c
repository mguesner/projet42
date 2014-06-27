/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affbis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:53:05 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:20:52 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>
#include <term.h>

void	ft_affbis(int i, int li, char line[1])
{
	ft_putstr("42sh: do you wish to see all ");
	ft_putnbr(i);
	ft_putstr(" possibilities (");
	ft_putnbr(li);
	ft_putstr(" lines)? ");
	while (read(0, line, 1))
	{
		if (*line == 'y' || *line == 'Y' || *line == '\t')
		{
			tputs(tgetstr("cb", NULL), 1, ft_putonterm);
			tputs(tgetstr("cr", NULL), 1, ft_putonterm);
			break ;
		}
		else
		{
			tputs(tgetstr("cb", NULL), 1, ft_putonterm);
			tputs(tgetstr("cr", NULL), 1, ft_putonterm);
			tputs(tgetstr("up", NULL), 1, ft_putonterm);
			tputs(tgoto(tgetstr("RI", NULL), 0, G_E), 1, ft_putonterm);
			return ;
		}
	}
}
