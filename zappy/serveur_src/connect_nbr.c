/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 15:40:30 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/19 15:30:14 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	connect_nbr(t_env *e, int fd)
{
	char	*tmp;
	t_list	*tmp2;

	tmp2 = e->names;
	while (tmp2)
	{
		if (!ft_strcmp(tmp2->name, e->clients[fd].name))
		{
			tmp = ft_itoa(tmp2->nb_connect);
			ft_strcat(e->clients[fd].buf_write, tmp);
			ft_strcat(e->clients[fd].buf_write, "\n");
			ft_strdel(&tmp);
			break ;
		}
		tmp2 = tmp2->next;
	}
}
