/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 10:23:14 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/12 11:22:16 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>

int		is_builtin(char *str)
{
	ft_strsupressslash(str);
	if (!ft_strcmp(str, "cd") || !ft_strcmp(str, "exit")
			|| !ft_strcmp(str, "setenv") || !ft_strcmp(str, "unsetenv")
			|| !ft_strcmp(str, "echo") || !ft_strcmp(str, "env"))
		return (1);
	return (0);
}
