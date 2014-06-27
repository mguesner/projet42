/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_gfx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 17:40:26 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/13 18:21:28 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

void	move_gfx(t_env *e, t_clients *player)
{
	char	*str;
	char	*str2;
	char	*tmp;

	tmp = ft_itoa(player->nb);
	str = ft_strtrijoin("move ", tmp, " ");
	ft_strdel(&tmp);
	tmp = ft_itoa(player->X);
	str2 = ft_strtrijoin(str, tmp, " ");
	ft_strdel(&tmp);
	ft_strdel(&str);
	tmp = ft_itoa(player->Y);
	str = ft_strtrijoin(str2, tmp, " ");
	ft_strdel(&tmp);
	ft_strdel(&str2);
	tmp = ft_itoa(player->orient);
	str2 = ft_strtrijoin(str, tmp, " ");
	ft_strdel(&tmp);
	ft_strdel(&str);
	str = ft_strtrijoin(str2, player->name, "\n");
	ft_strdel(&str2);
	maj_gfx(e, str);
	ft_strdel(&str);
}
