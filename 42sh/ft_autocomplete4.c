/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocomplete4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 13:09:03 by nguezell          #+#    #+#             */
/*   Updated: 2014/03/27 13:22:19 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

t_list	*ft_create_node(char *str)
{
	t_list	*node;
	int		i;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	node->next = NULL;
	node->pre = NULL;
	i = ft_isdir(str);
	node->content = (i == 0) ? ft_str_spe_dup(str) : ft_strjoin(str, "/");
	node->flag = i;
	return (node);
}

void	ft_first_node(t_list **lst, t_list *node)
{
	if (*(node->content) != '.')
		*lst = node;
	else
		ft_delnode(&node);
}

void	ft_insert_node(t_list *node, t_list *tmp, t_list **lst)
{
	if (tmp->pre)
	{
		node->next = tmp;
		node->pre = tmp->pre;
		tmp->pre->next = node;
		tmp->pre = node;
	}
	else
	{
		node->next = tmp;
		tmp->pre = node;
		*lst = node;
	}
}

void	ft_add_node(t_list **lst, char *str)
{
	t_list	*node;
	t_list	*tmp;

	node = ft_create_node(str);
	if (*lst == NULL)
		return (ft_first_node(lst, node));
	tmp = *lst;
	while (tmp->next && ft_strcmp(node->content, tmp->content) > 0)
		tmp = tmp->next;
	if (ft_strcmp(node->content, tmp->content) == 0
		|| !ft_strncmp(node->content, ".", 1))
		return (ft_delnode(&node));
	if (ft_strcmp(node->content, tmp->content) < 0)
		ft_insert_node(node, tmp, lst);
	else
	{
		tmp->next = node;
		node->pre = tmp;
	}
}

void	ft_add_tolist(t_list **lst, char *dirname, char *line)
{
	DIR				*dir;
	struct dirent	*directory;
	int				i;

	i = ft_strlen(line);
	if ((dir = opendir(dirname)) != NULL)
	{
		while ((directory = readdir(dir)))
		{
			if (!ft_strncmp(directory->d_name, line, i))
				ft_add_node(lst, directory->d_name);
		}
		closedir(dir);
	}
}
