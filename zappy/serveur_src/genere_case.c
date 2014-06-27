/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   genere_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 09:17:01 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/23 12:04:06 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <stdlib.h>
#include <libft.h>
#include <stdio.h>

t_case		genere_case(void)
{
	t_case		ret;

	ret.nourriture = (int)((float)rand() / RAND_MAX < RAND_NOURRITURE ? 1 : 0);
	ret.linemate = (int)((float)rand() / RAND_MAX < RAND_LINEMATE ? 1 : 0);
	ret.deraumere = (int)((float)rand() / RAND_MAX < RAND_DERAUMERE ? 1 : 0);
	ret.sibur = (int)((float)rand() / RAND_MAX < RAND_SIBUR ? 1 : 0);
	ret.mendiane = (int)((float)rand() / RAND_MAX < RAND_MENDIANE ? 1 : 0);
	ret.phiras = (int)((float)rand() / RAND_MAX < RAND_PHIRAS ? 1 : 0);
	ret.thystame = (int)((float)rand() / RAND_MAX < RAND_THSTAME ? 1 : 0);
	return (ret);
}
