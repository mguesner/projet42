/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:24:43 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/22 11:17:21 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <signal.h>

static void	ft_abort(int i)
{
	tcsetattr(0, TCSAFLUSH, &(g_e.old));
	tputs(tgetstr("ei", NULL), 1, ft_putonterm);
	write(2, "abort BIATCH\n", 16);
	exit(i);
}

static void	ft_segfault(int i)
{
	tcsetattr(0, TCSAFLUSH, &(g_e.old));
	tputs(tgetstr("ei", NULL), 1, ft_putonterm);
	write(2, "SEGFAULT BIATCH\n", 16);
	exit(i);
}

static void	ft_resize(int i)
{
	tgetent(NULL, getenv("TERM"));
	(void)i;
}

void		ft_signal(int i)
{
	if (!i)
	{
		signal(SIGINT, ft_reput_prompt);
		signal(SIGSEGV, ft_segfault);
		signal(SIGABRT, ft_abort);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGWINCH, ft_resize);
	}
	else if (i > 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGTSTP, SIG_IGN);
		signal(SIGINT, SIG_DFL);
	}
	else
		signal(SIGINT, SIG_IGN);
}
