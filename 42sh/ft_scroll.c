/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scroll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 15:55:22 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:55:36 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <term.h>

static void	ft_scroll3(int	k, t_list *current)
{
	int		j;

	j = 0;
	while (current->content[j] && current->content[j] == g_e.buff[k + j])
		j++;
	while (current->content[j])
	{
		ft_add(g_e.buff, g_e.i++, current->content[j], &g_e.size);
		ft_putchar(current->content[j++]);
	}
}

static void	ft_scroll2(int	*i)
{
	while (*i < g_e.i)
	{
		ft_del_char(g_e.buff, --g_e.i);
		tputs(tgetstr("le", NULL), 1, ft_putonterm);
		tputs(tgetstr("dc", NULL), 1, ft_putonterm);
	}
	ft_putstr(&g_e.buff[g_e.i]);
}

void		ft_scroll(t_list *lst, int mode)
{
	static t_list	*current = NULL;
	static int		i = 0;
	int				k;

	if (!mode || !current)
	{
		if (!mode)
			i = g_e.i;
		if (mode)
			ft_scroll2(&i);
		current = lst;
	}
	else
		ft_scroll2(&i);
	if (mode)
	{
		i = g_e.i;
		k = i;
		while (k > 0 && g_e.buff[k - 1] != ' ')
			k--;
		ft_scroll3(k, current);
		current = current->next;
	}
}
