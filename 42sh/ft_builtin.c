/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:13:35 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/22 11:27:15 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

int		ft_builtin(char *cmd, char ***env)
{
	char	**arg;
	int		ret;

	ret = -1;
	arg = ft_strsplit2(cmd, ' ');
	ft_supressslash(arg);
	if (!ft_strcmp(arg[0], "cd"))
		ret = ft_cd(arg, env);
	else if (!ft_strcmp(arg[0], "exit"))
		ft_exit(0);
	else if (!ft_strcmp(arg[0], "env"))
		ret = ft_env(arg, *env);
	else if (!ft_strcmp(arg[0], "setenv"))
		ret = ft_presetenv(arg, env);
	else if (!ft_strcmp(arg[0], "unsetenv"))
		ret = ft_unsetenv(arg, env);
	else if (!ft_strcmp(arg[0], "echo"))
		ret = ft_echo(arg);
	ft_tabdel(arg);
	free(arg);
	return (ret);
}
