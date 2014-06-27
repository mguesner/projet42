/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parserbis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 10:59:49 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 13:14:24 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>

int		ft_parsepipe(t_list **current, char **str)
{
	ft_strtrimbadass(*str);
	if (((*current)->flag == CMD || (*current)->flag == BUILTIN) && *(*str + 1))
	{
		(*current)->next = ft_create_elem("|", PIPE);
		(*str)++;
		*current = (*current)->next;
		return (0);
	}
	else if (!(*(*str + 1)))
	{
		write(2, "42sh: parse error near `\\n'\n", 29);
		return (1);
	}
	else
	{
		write(2, "42sh: parse error near `|'\n", 29);
		return (1);
	}
}

t_list	*ft_parser(char *str)
{
	t_list	*ret;
	t_list	*current;

	ret = ft_create_elem("debut", -1);
	current = ret;
	while (*str)
	{
		if ((*str && *str == '|' && *(str + 1) == '|'
				&& ft_parseor(&current, &str))
			|| (*str && *str == '|' && *(str + 1) != '|'
				&& ft_parsepipe(&current, &str))
			|| (*str && *str == '<' && ft_parseredir(&current, &str, '<'))
			|| (*str && *str == '>' && ft_parseredir(&current, &str, '>'))
			|| (*str && *str == ';' && ft_parseend(&current, &str))
			|| (*str && *str == '&' && *(str + 1) == '&'
				&& ft_parseand(&current, &str))
			|| (*str && *str != '|' && *str != '<' && *str != '>' && *str != ';'
				&& *str != '&' && ft_parsecmd(&current, &str)))
			return (ft_parseerror(&ret));
	}
	return (ret);
}
