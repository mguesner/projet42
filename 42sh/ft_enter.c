/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 17:30:09 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/21 15:05:37 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <libft.h>
#include "ft_sh.h"

void	ft_enter(char ***env)
{
	if (*g_e.line == 10)
	{
		ft_reset();
		tputs(tgetstr("do", NULL), 1, ft_putonterm);
		tputs(tgetstr("cr", NULL), 1, ft_putonterm);
		tputs(tgetstr("cd", NULL), 1, ft_putonterm);
		ft_strtrimbadass(g_e.buff);
		if (*g_e.buff)
		{
			ft_add_hystor(0);
			ft_go(env);
		}
		ft_strclr(g_e.buff);
		g_e.i = 0;
		ft_prompt(*env);
	}
}
