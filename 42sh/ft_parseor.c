/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:15:54 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 15:16:33 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>

int		ft_parseor(t_list **current, char **str)
{
	ft_strtrimbadass(*str);
	if (((*current)->flag == CMD || (*current)->flag == BUILTIN) && *(*str + 1))
	{
		(*current)->next = ft_create_elem("||", OR);
		(*str) += 2;
		*current = (*current)->next;
		return (0);
	}
	if (!(*(*str + 1)))
	{
		write(2, "42sh: parse error near `\\n'\n", 29);
		return (1);
	}
	write(2, "42sh: parse error near `||'\n", 30);
	return (1);
}
