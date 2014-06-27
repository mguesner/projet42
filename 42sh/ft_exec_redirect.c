/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 15:23:58 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:03:47 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <fcntl.h>
#include <unistd.h>
#include <libft.h>

static int	ft_redir2(int redir, char *cmd)
{
	int		fd;

	if (redir == 1)
	{
		close(0);
		ft_strtrimbadass(cmd);
		if (((fd = open(cmd, O_RDONLY)) == -1))
			return (ft_file_error(cmd));
		dup(fd);
	}
	else if (redir == 2 || redir == 3)
	{
		close(1);
		ft_strtrimbadass(cmd);
		if ((redir == 2
					&& (fd = open(cmd, O_WRONLY | O_CREAT
							| O_TRUNC, 0644)) == -1) || (redir == 3
						&& (fd = open(cmd, O_WRONLY | O_CREAT
								| O_APPEND, 0644)) == -1))
			return (ft_file_error(cmd));
		dup(fd);
	}
	return (1);
}

static int	ft_redir(t_tree *tree, char *redir)
{
	int		ret;

	ret = 1;
	if (tree->flag == FILES)
	{
		if (*(redir) == '<')
			ret = ft_redir2(1, tree->content);
		else if (*(redir) == '>' && *(redir + 1) != '>')
			ret = ft_redir2(2, tree->content);
		else if (*(redir) == '>' && *(redir + 1) == '>')
			ret = ft_redir2(3, tree->content);
	}
	else
	{
		if (tree->left)
			ret = ft_redir(tree->left, redir);
		if (tree->right)
			ret = ft_redir(tree->right, tree->content);
	}
	return (ret);
}

int			ft_exec_redirect(t_tree *tree, char **path, char ***env)
{
	int		ret;
	int		stdin_cpy;
	int		stdout_cpy;

	stdin_cpy = dup(0);
	stdout_cpy = dup(1);
	ret = ft_redir(tree->right, tree->content);
	if (ret && tree->left && tree->left->flag == BUILTIN)
		ret = ft_builtin(tree->left->content, env);
	else if (ret && tree->left && tree->left->flag == CMD)
		ret = ft_fork(tree->left->content, path, env);
	dup2(stdin_cpy, 0);
	dup2(stdout_cpy, 1);
	return (ret);
}
