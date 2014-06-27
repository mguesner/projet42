/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:25:03 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/25 14:05:59 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include <libft.h>
#include "ft_sh.h"

void	ft_init(void)
{
	tgetent(NULL, getenv("TERM"));
	tputs(tgetstr("im", NULL), 1, ft_putonterm);
	tcgetattr(0, &(g_e.old));
	tcgetattr(0, &(g_e.termios_p));
	g_e.termios_p.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(0, TCSADRAIN, &(g_e.termios_p));
}
