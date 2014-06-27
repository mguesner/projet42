/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:08:41 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:21:39 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>

static void	ft_puterror(char *str, char *error)
{
	write(2, "42sh: ", 6);
	write(2, error, ft_strlen(error));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	_exit(-1);
}

int			ft_cmd(char *cmd, char **path, char ***env)
{
	char	**arg;
	char	*tmp;
	int		i;

	arg = ft_strsplit2(cmd, ' ');
	ft_supressslash(arg);
	i = 0;
	while (path[i])
	{
		tmp = ft_strtrijoin(path[i], "/", arg[0]);
		if (access(tmp, F_OK) == 0 && execve(tmp, arg, *env) == -1)
			ft_puterror(arg[0], "permission denied");
		ft_strdel(&tmp);
		i++;
	}
	if (access(arg[0], F_OK) == 0 && execve(arg[0], arg, *env) == -1)
		ft_puterror(arg[0], "permission denied");
	ft_puterror(arg[0], "command not found");
	return (-1);
}
