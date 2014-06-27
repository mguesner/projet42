/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 14:00:12 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 15:15:00 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>

int		ft_parseand(t_list **current, char **str)
{
	ft_strtrimbadass(*str);
	if (((*current)->flag == CMD || (*current)->flag == BUILTIN) && *(*str + 1))
	{
		(*current)->next = ft_create_elem("&&", AND);
		(*str) += 2;
		*current = (*current)->next;
		return (0);
	}
	if (!(*(*str + 1)))
	{
		write(2, "42sh: parse error near `\\n'\n", 29);
		return (1);
	}
	write(2, "42sh: parse error near `&&'\n", 30);
	return (1);
}
