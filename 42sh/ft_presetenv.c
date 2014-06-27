/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 11:50:51 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/05 11:53:45 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <string.h>

int		ft_presetenv(char **arg, char ***env)
{
	if (!arg[1])
		ft_env(NULL, *env);
	else if (ft_getenv(arg[1], *env))
	{
		if (arg[2])
			ft_setenv(env, arg[1], arg[2]);
		else
			ft_setenv(env, arg[1], "");
	}
	else
	{
		ft_add_env(env, arg[1]);
		if (arg[2])
			ft_setenv(env, arg[1], arg[2]);
	}
	return (0);
}
