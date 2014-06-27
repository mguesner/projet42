/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 11:50:45 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:25:45 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>

int		ft_exec(t_tree *tree, char **path, char ***env)
{
	int		ret;

	if (tree->flag == END)
	{
		if (tree->left)
			ret = ft_exec(tree->left, path, env);
		if (tree->right)
			ret = ft_exec(tree->right, path, env);
		return (ret);
	}
	if (tree->flag == OR)
		return (ft_exec(tree->left, path, env) == 0
		|| ft_exec(tree->right, path, env) == 0);
	if (tree->flag == AND)
		return (ft_exec(tree->left, path, env) == 0
		&& ft_exec(tree->right, path, env) == 0);
	if (tree->flag == PIPE)
		return (ft_exec_pipe(tree, path, env));
	if (tree->flag == REDIRECT)
		return (ft_exec_redirect(tree, path, env));
	if (tree->flag == BUILTIN)
		return (ft_builtin(tree->content, env));
	return (ft_fork(tree->content, path, env));
}
