/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseredir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 07:17:34 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 15:15:32 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>

int		ft_parsefile(t_list **current, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] && (*str)[i] != ' ' && !ft_isop((*str)[i]))
		i++;
	tmp = ft_strsub(*str, 0, i);
	(*current)->next = ft_create_elem(tmp, FILES);
	ft_strdel(&tmp);
	*str = (*str) + i;
	*current = (*current)->next;
	return (0);
}

int		ft_parseredir(t_list **current, char **str, char c)
{
	char	*tmp;

	if (*(*str + 1) == c)
		tmp = ft_createstr(c, 2);
	else
		tmp = ft_createstr(c, 1);
	(*current)->next = ft_create_elem(tmp, REDIRECT);
	(*str) = (*str) + ft_strlen(tmp);
	(*current) = (*current)->next;
	ft_strdel(&tmp);
	ft_strtrimbadass(*str);
	if (!ft_isop(**str) && *(*str))
		return (ft_parsefile(current, str));
	else if (!(**str))
	{
		write(2, "42sh: parse error near `\\n'\n", 29);
		return (1);
	}
	write(2, "42sh: parse error near `", 26);
	if (**str == *(*str + 1) && (**str == '<' || **str == '>'))
		write(2, *str, 2);
	else
		write(2, *str, 1);
	write(2, "'\n", 2);
	return (1);
}
