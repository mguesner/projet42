/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftson.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:33:28 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:39:16 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>

void		ft_leftson(int fd[2], t_tree *tree, char **path, char ***env)
{
	close(fd[0]);
	dup2(fd[1], 1);
	if (tree->left->flag == CMD)
	{
		ft_signal(1);
		_exit(ft_cmd(tree->left->content, path, env));
	}
	_exit(ft_exec(tree->left, path, env));
}
