/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:32:44 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:56:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>
#include <libft.h>

t_tree	*ft_make_tree1(t_list *arg)
{
	t_list	*current;
	t_list	*pre;
	t_tree	*ret;

	current = arg->next;
	pre = arg;
	while (current)
	{
		if (current->flag == END)
		{
			ret = ft_new_node(current);
			pre->next = NULL;
			ret->left = ft_make_tree(arg);
			if (current->next)
				ret->right = ft_make_tree(current->next);
			ft_strdel(&current->content);
			free(current);
			return (ret);
		}
		current = current->next;
		pre = pre->next;
	}
	return (NULL);
}

t_tree	*ft_make_tree2(t_list *arg)
{
	t_list	*current;
	t_list	*pre;
	t_tree	*ret;

	current = arg->next;
	pre = arg;
	while (current)
	{
		if (current->flag == AND || current->flag == OR)
		{
			ret = ft_new_node(current);
			pre->next = NULL;
			ret->left = ft_make_tree(arg);
			ret->right = ft_make_tree(current->next);
			ft_strdel(&current->content);
			free(current);
			return (ret);
		}
		current = current->next;
		pre = pre->next;
	}
	return (NULL);
}

t_tree	*ft_make_tree3(t_list *arg)
{
	t_list	*current;
	t_list	*pre;
	t_tree	*ret;

	current = arg->next;
	pre = arg;
	while (current)
	{
		if (current->flag == PIPE)
		{
			ret = ft_new_node(current);
			pre->next = NULL;
			ret->left = ft_make_tree(arg);
			ret->right = ft_make_tree(current->next);
			ft_strdel(&current->content);
			free(current);
			return (ret);
		}
		current = current->next;
		pre = pre->next;
	}
	return (NULL);
}

t_tree	*ft_make_tree4(t_list *arg)
{
	t_list	*current;
	t_list	*pre;

	current = arg->next;
	pre = arg;
	while (current)
	{
		if (current->flag == REDIRECT)
			return (ft_make_treebis2(current, pre, arg));
		else if (pre->flag == REDIRECT)
			return (ft_make_treebis(current, pre));
		current = current->next;
		pre = pre->next;
	}
	return (NULL);
}

t_tree	*ft_make_tree(t_list *arg)
{
	t_tree	*ret;
	t_list	*tmp;

	ft_arg_del(&arg);
	if (arg && arg->next)
	{
		if ((ret = ft_make_tree1(arg)))
			return (ret);
		if ((ret = ft_make_tree2(arg)))
			return (ret);
		if ((ret = ft_make_tree3(arg)))
			return (ret);
		if ((ret = ft_make_tree4(arg)))
			return (ret);
		ret = ft_new_node(arg);
		ft_strdel(&arg->content);
		tmp = arg->next;
		free(arg);
		arg = tmp;
		return (ret);
	}
	ret = ft_new_node(arg);
	ft_strdel(&arg->content);
	free(arg);
	return (ret);
}
