/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 17:42:59 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/29 17:53:16 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <libft.h>

void	ft_putmap(char *map)
{
	int		i;

	i = 0;
	ft_printf("map :\n");
	while (i < SIZE * SIZE)
	{
		ft_printf("%c", map[i]);
		if (i % SIZE == SIZE - 1)
			ft_printf("\n");
		i++;
	}
}
