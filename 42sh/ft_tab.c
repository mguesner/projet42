/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 14:21:45 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/23 15:21:15 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <stdlib.h>

void	ft_tab(char **env)
{
	char	**path;
	char	*tmp;

	if (!(tmp = ft_getenv("PATH", env)))
		path = ft_path();
	else
		path = ft_strsplit(tmp, ':');
	if (*g_e.line == '\t')
	{
		if (g_e.autocomplete < 0)
			g_e.choice = ft_autocomplete(g_e.buff, path);
		ft_aff(g_e.choice);
	}
	ft_tabdel(path);
	free(path);
}
