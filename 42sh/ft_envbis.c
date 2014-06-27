/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envbis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:12:21 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:31:50 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

static void		ft_affenv(char **env)
{
	int		i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			ft_putendl(env[i]);
			ft_strdel(&(env[i]));
			i++;
		}
	}
}

static void		ft_exec_env(char **arg, char ***env)
{
	int		i;
	char	*cmd;
	char	**path;
	char	*tmp;
	t_list	*lst;
	t_tree	*tree;

	i = 0;
	cmd = ft_strnew(0);
	if (!(tmp = ft_getenv("PATH", *env)))
		path = ft_path();
	else
		path = ft_strsplit(tmp, ':');
	while (arg[i])
	{
		tmp = ft_strtrijoin(cmd, arg[i], " ");
		ft_strdel(&cmd);
		cmd = tmp;
		i++;
	}
	lst = ft_parser(cmd);
	tree = ft_make_tree(lst);
	ft_exec(tree, path, env);
	ft_deleter(tree, path, env, &cmd);
}

int				ft_envbis(char **arg, int i, char **env_cpy)
{
	char	*tmp;

	while (arg && arg[i] && ft_strchr(arg[i], '='))
	{
		tmp = ft_strcut(arg[i], '=');
		ft_setenv(&env_cpy, tmp, ft_strchr(arg[i], '=') + 1);
		ft_strdel(&tmp);
		i++;
	}
	if (arg && arg[i])
		ft_exec_env(&(arg[i]), &env_cpy);
	else
		ft_affenv(env_cpy);
	free(env_cpy);
	return (0);
}
