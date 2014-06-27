/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 13:46:07 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:32:51 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <libft.h>
#include <sys/wait.h>

static int	ft_exec_pipe_builtin(t_tree *tree, char **path, char ***env)
{
	pid_t	left_son;

	left_son = fork();
	if (left_son == 0)
	{
		close(1);
		ft_exec(tree->left, path, env);
		_exit(0);
	}
	else
	{
		waitpid(left_son, NULL, 0);
		return (ft_exec(tree->right, path, env));
	}
}

void		ft_rightson(int fd[2], t_tree *tree, char **path, char ***env)
{
	close(fd[1]);
	dup2(fd[0], 0);
	if (tree->right->flag == CMD)
	{
		ft_signal(1);
		_exit(ft_cmd(tree->right->content, path, env));
	}
	_exit(ft_exec(tree->right, path, env));
}

int			ft_father(int *stat_loc, t_tree *tree
		, pid_t right_son, pid_t left_son)
{
	if (stat_loc || waitpid(left_son, stat_loc, 0) >= 0)
	{
		ft_signal(0);
		if (WIFEXITED(*stat_loc))
			WEXITSTATUS(*stat_loc);
		if (WIFSIGNALED(*stat_loc))
			ft_end(*stat_loc, tree->left->content);
	}
	if (waitpid(right_son, stat_loc, 0) >= 0)
	{
		ft_signal(0);
		if (WIFEXITED(*stat_loc))
			return (WEXITSTATUS(*stat_loc));
		if (WIFSIGNALED(*stat_loc))
			return (ft_end(*stat_loc, tree->left->content));
	}
	return (-1);
}

static int	ft_exec_pipe_pipe(t_tree *tree, char **path, char ***env)
{
	pid_t	left_son;
	pid_t	right_son;
	int		fd[2];
	int		stat_loc;

	pipe(fd);
	ft_signal(-1);
	stat_loc = 0;
	left_son = fork();
	if (left_son)
		right_son = fork();
	if (!left_son)
		ft_leftson(fd, tree, path, env);
	else if (!right_son && waitpid(left_son, &stat_loc, WUNTRACED))
		ft_rightson(fd, tree, path, env);
	else if (right_son && left_son)
	{
		close(fd[0]);
		close(fd[1]);
		return (ft_father(&stat_loc, tree, right_son, left_son));
	}
	return (-1);
}

int			ft_exec_pipe(t_tree *tree, char **path, char ***env)
{
	if (tree->right->flag == BUILTIN)
		return (ft_exec_pipe_builtin(tree, path, env));
	return (ft_exec_pipe_pipe(tree, path, env));
}
