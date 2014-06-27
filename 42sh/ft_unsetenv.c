/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 14:03:47 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/05 12:14:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>

int		ft_unsetenv(char **arg, char ***env)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[1] && (*env)[i])
	{
		if (!ft_strncmp((*env)[i], arg[1], ft_strlen(arg[1])))
		{
			ft_strdel(&(*env)[i]);
			j = i + 1;
		}
		if (j)
		{
			(*env)[i] = (*env)[j];
			j++;
		}
		i++;
	}
	(*env)[i] = NULL;
	return (0);
}
