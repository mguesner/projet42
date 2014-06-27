/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:49:53 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:32:24 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

void	ft_go(char ***env)
{
	char	*tmp;
	char	**path;
	t_list	*arg;
	t_tree	*tree;

	if (!(tmp = ft_getenv("PATH", *env)))
		path = ft_path();
	else
		path = ft_strsplit(tmp, ':');
	if ((arg = ft_parser(g_e.buff))
			&& (tree = ft_make_tree(arg)))
	{
		ft_exec(tree, path, env);
		ft_del_tree(tree);
	}
	ft_tabdel(path);
	free(path);
}
