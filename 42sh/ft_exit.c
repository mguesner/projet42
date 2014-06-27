/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 14:33:17 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/02 11:42:22 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <unistd.h>
#include <libft.h>
#include "ft_sh.h"

void	ft_exit(int	a)
{
	tcsetattr(0, TCSAFLUSH, &(g_e.old));
	tputs(tgetstr("ei", NULL), 1, ft_putonterm);
	ft_putendl("exit");
	_exit(a);
}
