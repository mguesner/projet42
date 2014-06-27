/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:39:58 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/28 17:27:07 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>

t_tree	*ft_new_node(t_list *arg)
{
	t_tree	*ret;

	if (arg)
	{
		ret = (t_tree *)ft_memalloc(sizeof(t_tree));
		ret->content = ft_strdup(arg->content);
		ret->flag = arg->flag;
		ret->right = NULL;
		ret->left = NULL;
		return (ret);
	}
	return (NULL);
}
