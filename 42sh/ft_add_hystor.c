/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_hystor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 12:35:16 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/12 14:13:43 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

void	ft_add_hystor(int mode)
{
	if (!g_e.hystor)
	{
		g_e.hystor = ft_create_elem(g_e.buff, mode);
		g_e.hystor->pre = NULL;
	}
	else
	{
		while (g_e.hystor->next && g_e.hystor->next->flag != 1)
			g_e.hystor = g_e.hystor->next;
		if (g_e.hystor->next || (g_e.hystor->flag
					&& (g_e.hystor = g_e.hystor->pre)))
		{
			ft_strdel(&(g_e.hystor->next->content));
			free(g_e.hystor->next);
		}
		g_e.hystor->next = ft_create_elem(g_e.buff, mode);
		g_e.hystor->next->pre = g_e.hystor;
		g_e.hystor = g_e.hystor->next;
	}
}
