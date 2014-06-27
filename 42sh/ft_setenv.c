/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 11:00:48 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 15:16:27 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_sh.h"

void	ft_setenv(char ***env, char *line, char *str)
{
	int		i;
	int		done;

	done = 0;
	i = 0;
	while ((*env)[i])
	{
		if (*line && !ft_strncmp((*env)[i], line, ft_strlen(line)))
		{
			ft_strdel(&((*env)[i]));
			(*env)[i] = ft_strtrijoin(line, "=", str);
			done = 1;
		}
		if (!*line && (*(*env)[i]) == '=' && (done = 1))
		{
			ft_strdel(&((*env)[i]));
			(*env)[i] = ft_strjoin("=", str);
		}
		i++;
	}
	if (!done)
	{
		ft_add_env(env, line);
		ft_setenv(env, line, str);
	}
}
