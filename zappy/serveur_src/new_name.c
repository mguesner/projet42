/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 11:41:33 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/07 11:46:59 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

t_list	*new_name(char *name)
{
	t_list	*ret;

	ret = ft_memalloc(sizeof(t_list));
	ret->name = ft_strdup(name);
	ret->next = NULL;
	return (ret);
}
