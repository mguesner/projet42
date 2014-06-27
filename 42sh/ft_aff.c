/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 11:24:59 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 14:28:33 by jrivaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <term.h>
#include <libft.h>
#include <unistd.h>

static void	ft_alone(t_list *lst)
{
	int		i;
	int		j;

	i = g_e.i;
	while (i > 0 && g_e.buff[i - 1] != ' ' && g_e.buff[i - 1] != '/')
		i--;
	j = 0;
	while (lst->content[j] == g_e.buff[i + j])
		j++;
	while (lst->content[j])
	{
		ft_add(g_e.buff, g_e.i++, lst->content[j], &g_e.size);
		ft_putchar(lst->content[j++]);
	}
	if (lst->flag != 1)
	{
		ft_add(g_e.buff, g_e.i++, ' ', &g_e.size);
		ft_putchar(' ');
	}
}

static void	ft_aff3(t_list *lst, int li, int co, int size)
{
	int		i;
	int		j;
	t_list	*current;

	g_e.autocomplete = 0;
	j = 0;
	current = lst;
	while (j < co)
	{
		i = 0;
		while (i < li && current)
		{
			if (size * j)
				tputs(tgoto(tgetstr("RI", NULL), 0, size * j), 1, ft_putonterm);
			ft_putendl(current->content);
			current = current->next;
			i++;
		}
		if (i)
			tputs(tgoto(tgetstr("UP", NULL), 0, i), 1, ft_putonterm);
		j++;
	}
	tputs(tgetstr("up", NULL), 1, ft_putonterm);
	tputs(tgoto(tgetstr("RI", NULL), 0, g_e.prompt + g_e.i), 1, ft_putonterm);
}

static void	ft_aff2(t_list *lst, int i, int size)
{
	int		co;
	int		li;
	char	line[1];

	co = tgetnum("co") / (size + 7);
	li = i / (co + 1);
	ft_putchar('\n');
	tputs(tgetstr("cd", NULL), 1, ft_putonterm);
	if (li > tgetnum("li") - 5)
	{
		ft_putstr("42sh: too many line");
		tputs(tgetstr("up", NULL), 1, ft_putonterm);
		tputs(tgoto(tgetstr("LE", NULL), 0, 19), 1, ft_putonterm);
		tputs(tgoto(tgetstr("RI", NULL), 0, G_E), 1, ft_putonterm);
		return ;
	}
	if (i > 100)
		ft_affbis(i, li, line);
	ft_aff3(lst, li + 1, co + 1, size + 2);
}

static int	ft_samebegin(t_list *lst, t_list *current)
{
	int		i;
	int		j;
	int		ret;

	ret = 0;
	i = g_e.i;
	while (i > 0 && g_e.buff[i - 1] != ' ' && g_e.buff[i - 1] != '/')
		i--;
	j = 0;
	while (lst->content[j] == g_e.buff[i + j])
		j++;
	while (lst->content[j] && lst->content[j] == current->content[j])
	{
		ret = 1;
		ft_add(g_e.buff, g_e.i++, lst->content[j], &g_e.size);
		ft_putchar(lst->content[j++]);
	}
	return (ret);
}

void		ft_aff(t_list *lst)
{
	int		i;
	int		size;
	int		tmp;
	t_list	*current;

	if (lst && (i = 1))
	{
		current = lst;
		size = 0;
		while (current->next)
		{
			i++;
			if ((tmp = ft_strlen(current->content)) > size)
				size = tmp;
			current = current->next;
		}
		if (i == 1 && g_e.autocomplete < 0)
			ft_alone(lst);
		else if (i > 1 && g_e.autocomplete < 0 && ft_samebegin(lst, current))
			return ;
		else if (g_e.autocomplete < 0)
			ft_aff2(lst, i, size);
		else
			ft_scroll(lst, 1);
	}
}
