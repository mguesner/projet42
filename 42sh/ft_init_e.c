/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 13:07:03 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/17 16:10:44 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>

void	ft_init_e(void)
{
	g_e.i = 0;
	g_e.autocomplete = -1;
	ft_strclr(g_e.line);
	g_e.size = 2048;
	g_e.buff = (char *)ft_memalloc((2048 * sizeof(char)));
}
