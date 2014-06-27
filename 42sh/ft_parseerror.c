/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 10:19:44 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 11:00:28 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

t_list	*ft_parseerror(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		ft_strdel(&((*list)->content));
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
	return (NULL);
}
