/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 16:09:53 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/26 17:16:33 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>

t_list	*ft_create_elem(char *str, int	flag)
{
	t_list	*ret;

	ret = (t_list *)ft_memalloc(sizeof(t_list));
	ret->content = ft_strdup(str);
	ret->next = NULL;
	ret->flag = flag;
	return (ret);
}
