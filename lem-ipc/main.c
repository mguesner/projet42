/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 13:29:23 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 16:51:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <libft.h>

int		main(int argc, char **argv)
{
	if (argc == 2 && ft_strlen(argv[1]) == 1
		&& *argv[1] > '0' && *argv[1] < '8')
		ft_lemipc(ft_atoi(argv[1]), ftok("lemipc.h", 'k'));
	else
		ft_printf("Usage : ./lemipc [team 1-7]\n");
	return (0);
}
