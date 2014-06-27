/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 16:43:55 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/04 17:18:18 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

t_tree	*ft_big_node(t_list *arg)
{
	t_tree	*ret;
	t_list	*tmp;

	str = ft_strnew(0);
	ret = (t_tree *)ft_memalloc(sizeof(t_tree));
	ret->flag = arg->flag;
	ret->content = arg->content;
	ft_strdel(arg->content);
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}
