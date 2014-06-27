/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 13:32:35 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:30:59 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdlib.h>
#include "ft_sh.h"

static int		ft_option(char **arg, int i, int *mode)
{
	int		j;

	j = 1;
	while (arg[i][j] == 'i')
	{
		*mode = 1;
		j++;
	}
	if (arg[i][j])
	{
		write(2, "42sh: env: -", 13);
		write(2, &(arg[i][j]), 1);
		write(2, ": invalid option\nenv: usage: env [-i] [name=value ...]", 54);
		write(2, " [utility [argument ...]]\n", 26);
		return (-1);
	}
	return (0);
}

void			ft_deleter(t_tree *tree, char **path, char ***env, char **cmd)
{
	ft_del_tree(tree);
	ft_tabdel(path);
	free(path);
	ft_tabdel(*env);
	ft_strdel(cmd);
}

int				ft_env(char **arg, char **env)
{
	int		i;
	int		mode;
	char	**env_cpy;

	i = 1;
	mode = 0;
	while (arg && arg[i] && *(arg[i]) == '-')
	{
		if (ft_option(arg, i, &mode))
			return (-1);
		if (arg[i][1] == '-')
			break ;
		i++;
	}
	env_cpy = (char **)ft_memalloc(1 * sizeof(char *));
	*env_cpy = NULL;
	if (!mode)
	{
		free(env_cpy);
		env_cpy = ft_cpyenv(env);
	}
	return (ft_envbis(arg, i, env_cpy));
}
