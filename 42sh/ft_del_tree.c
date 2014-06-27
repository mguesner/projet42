/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 17:41:07 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/09 17:48:04 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_sh.h"

void	ft_del_tree(t_tree *tree)
{
	if (tree->right)
		ft_del_tree(tree->right);
	if (tree->left)
		ft_del_tree(tree->left);
	ft_strdel(&tree->content);
	free(tree);
}
