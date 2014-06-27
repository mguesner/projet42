/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pond_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/08 18:20:57 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/25 14:08:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdio.h>
#include <libft.h>

void	pond_gfx(t_env *e, t_oeuf *oeuf)
{
	char	tmp[4096];

	ft_printf("pond %d %d %d %s\n", oeuf->x, oeuf->y, oeuf->nb, oeuf->team);
	sprintf(tmp, "pond %d %d %d %s\n", oeuf->x, oeuf->y, oeuf->nb, oeuf->team);
	maj_gfx(e, tmp);
}
