/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 07:41:32 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 15:16:07 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>

int		ft_parseend(t_list **current, char **str)
{
	if ((*current)->flag == CMD || (*current)->flag == BUILTIN
			|| (*current)->flag == FILES
			|| (*current)->flag == END || (*current)->flag == -1)
	{
		(*current)->next = ft_create_elem(";", END);
		(*str)++;
		*current = (*current)->next;
		ft_strtrimbadass(*str);
		return (0);
	}
	write(2, "42sh: parse error near `;'\n", 29);
	return (1);
}
