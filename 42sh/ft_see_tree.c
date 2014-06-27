/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_see_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 07:08:07 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 16:36:48 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <libft.h>

void	ft_see_tree(t_tree *tree, int i)
{
	if (tree->left)
		ft_see_tree(tree->left, i + 1);
	write(1, " <- ", 4);
	ft_putnbr(i);
	write(1, " : ", 3);
	write(1, tree->content, ft_strlen(tree->content));
	write(1, " -> ", 4);
	if (tree->right)
		ft_see_tree(tree->right, i + 1);
}
