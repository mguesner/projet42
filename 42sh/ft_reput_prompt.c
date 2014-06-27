/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reput_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:35:14 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/18 09:40:02 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <term.h>

void	ft_reput_prompt(int a)
{
	ft_reset();
	tputs(tgetstr("do", NULL), 1, ft_putonterm);
	tputs(tgetstr("cr", NULL), 1, ft_putonterm);
	tputs(tgetstr("cd", NULL), 1, ft_putonterm);
	ft_prompt(ft_stock(NULL, 1));
	ft_strclr(g_e.buff);
	g_e.i = 0;
	(void)a;
}
