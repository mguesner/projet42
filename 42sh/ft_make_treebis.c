/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_treebis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:40:48 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:56:26 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

void	ft_arg_del(t_list **arg)
{
	t_list	*tmp;

	while (*arg && ((*arg)->flag == END || (*arg)->flag == -1))
	{
		ft_strdel((&(*arg)->content));
		tmp = (*arg)->next;
		free(*arg);
		(*arg) = tmp;
	}
}

t_tree	*ft_make_treebis(t_list *current, t_list *pre)
{
	t_tree	*ret;
	t_list	*tmp;

	ret = ft_new_node(pre);
	if (current->next)
	{
		tmp = current->next->next;
		current->next->next = NULL;
		ret->left = ft_make_tree(current->next);
		current->next = tmp;
	}
	ret->right = ft_make_tree(current);
	ft_strdel(&pre->content);
	free(pre);
	return (ret);
}

t_tree	*ft_make_treebis2(t_list *current, t_list *pre, t_list *arg)
{
	t_tree	*ret;

	ret = ft_new_node(current);
	pre->next = NULL;
	if (*(arg->content))
		ret->left = ft_make_tree(arg);
	else
		ret->left = NULL;
	ret->right = ft_make_tree(current->next);
	ft_strdel(&current->content);
	free(current);
	return (ret);
}
