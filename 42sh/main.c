/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:09:00 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/12 15:31:31 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>

int		main(void)
{
	char	**env;

	if (!(env = creat_env()))
		ft_error("can't launch 42sh");
	ft_init();
	ft_stock(env, 0);
	ft_signal(0);
	ft_sh(env);
	return (0);
}
