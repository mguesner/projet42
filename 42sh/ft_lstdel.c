/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 17:33:00 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/26 17:36:37 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

void	ft_lstdel(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		ft_strdel(&(lst->content));
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
