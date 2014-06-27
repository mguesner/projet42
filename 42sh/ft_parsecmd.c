/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsecmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 08:52:04 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/24 14:12:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

static int	ft_parsecmd2(char **str, int slash, t_list **current, char *tmp)
{
	int		i;
	char	*tmp2;

	i = 0;
	while ((i && (*str)[i - 1] == '\\' && slash)
			|| ((*str)[i] && !ft_isop((*str)[i])))
	{
		if (i && (*str)[i - 1] == '\\')
			slash = 0;
		else
			slash = 1;
		i++;
	}
	tmp2 = ft_strsub(*str, 0, i);
	if (tmp && is_builtin(tmp))
		(*current)->next = ft_create_elem(tmp2, BUILTIN);
	else
		(*current)->next = ft_create_elem(tmp2, CMD);
	*str = (*str) + i;
	*current = (*current)->next;
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (0);
}

int			ft_parsecmd(t_list **current, char **str)
{
	int		i;
	int		slash;
	char	*tmp;

	i = 1;
	slash = 1;
	ft_strtrimbadass(*str);
	while (((*str)[i - 1] == '\\' && slash) || ((*str)[i] && (*str)[i] != ' '
				&& !ft_isop((*str)[i])))
	{
		if ((*str)[i - 1] == '\\')
			slash = 0;
		else
			slash = 1;
		i++;
	}
	tmp = ft_strsub(*str, 0, i);
	return (ft_parsecmd2(str, slash, current, tmp));
}
