/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 07:29:58 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:19:09 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <string.h>

void	ft_reset(void)
{
	ft_scroll(NULL, 0);
	ft_lstdel(g_e.choice);
	g_e.choice = NULL;
	g_e.autocomplete = -1;
}
