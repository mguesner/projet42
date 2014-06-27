/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 19:22:57 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/05 12:24:18 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

void	ft_add_env(char ***env, char *str)
{
	int		i;
	char	**new;

	i = 0;
	while ((*env)[i])
		i++;
	new = (char **)ft_memalloc((size_t)(i + 2) * sizeof(char *));
	new[i] = ft_strjoin(str, "=");
	new[i + 1] = NULL;
	i--;
	while (i >= 0)
	{
		new[i] = ft_strdup((*env)[i]);
		i--;
	}
	ft_tabdel(*env);
	free(*env);
	*env = new;
}
