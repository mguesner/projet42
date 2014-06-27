/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/12 14:19:14 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/12 14:24:40 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		ex_dir(t_clients *src, t_clients *dst)
{
	if (src->orient == dst->orient)
		return (5);
	if (src->orient == dst->orient + 1)
		return (3);
	if (src->orient == dst->orient + 2)
		return (1);
	if (src->orient == dst->orient + 3)
		return (7);
	return (0);
}
