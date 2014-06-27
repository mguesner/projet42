/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 14:48:19 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:33:54 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <libft.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <term.h>

int		ft_end(int	stat_loc, char *cmd)
{
	if (WTERMSIG(stat_loc) == SIGSEGV)
	{
		write(2, "42sh: SEGFAULT BIATCH ", 22);
		ft_putendl(cmd);
	}
	else if (WTERMSIG(stat_loc) == SIGABRT)
	{
		write(2, "42sh: ABORT BIATCH ", 19);
		ft_putendl(cmd);
	}
	else if (WTERMSIG(stat_loc) == SIGBUS)
	{
		write(2, "42sh: BUS ERROR BIATCH ", 23);
		ft_putendl(cmd);
	}
	else if (WTERMSIG(stat_loc) == SIGINT)
		ft_putendl("");
	else if (WTERMSIG(stat_loc) == SIGQUIT)
	{
		write(2, "42sh: quit      ", 16);
		ft_putendl(cmd);
	}
	return (WTERMSIG(stat_loc));
}

int		ft_fork(char *cmd, char **path, char ***env)
{
	int		stat_loc;
	pid_t	son;

	ft_signal(-1);
	son = fork();
	if (!son)
	{
		ft_signal(1);
		tcsetattr(0, TCSAFLUSH, &(g_e.old));
		tputs(tgetstr("ei", NULL), 1, ft_putonterm);
		_exit(ft_cmd(cmd, path, env));
	}
	else if (waitpid(son, &stat_loc, WUNTRACED) >= 0)
	{
		tcsetattr(0, TCSADRAIN, &(g_e.termios_p));
		tputs(tgetstr("im", NULL), 1, ft_putonterm);
		ft_signal(0);
		if (WIFEXITED(stat_loc))
			return (WEXITSTATUS(stat_loc));
		if (WIFSIGNALED(stat_loc))
			return (ft_end(stat_loc, cmd));
	}
	return (-1);
}
