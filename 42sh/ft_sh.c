/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 13:59:18 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/18 08:09:39 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <libft.h>
#include "ft_sh.h"

void	ft_sh(char **env)
{
	ft_init_e();
	ft_prompt(env);
	while (read(0, g_e.line, 3))
	{
		ft_print();
		ft_arrow();
		ft_enter(&env);
		ft_hystor();
		ft_tab(env);
		ft_strclr(g_e.line);
	}
	ft_exit(0);
}
