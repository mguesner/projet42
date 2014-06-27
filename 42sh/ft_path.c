/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 14:06:23 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/05 11:18:06 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**ft_duptab(char **tab)
{
	int		i;
	char	**ret;

	i = 0;
	while (tab[i])
		i++;
	ret = (char **)ft_memalloc((i + 1) * sizeof(char *));
	tab[i] = NULL;
	i--;
	while (i >= 0)
	{
		ret[i] = ft_strdup(tab[i]);
		i--;
	}
	return (ret);
}

char		**ft_path(void)
{
	static char	**path = NULL;

	if (!path)
	{
		path = (char **)ft_memalloc(8 * sizeof(char *));
		path[0] = ft_strdup("/usr/local/bin");
		path[1] = ft_strdup("/usr/bin");
		path[2] = ft_strdup("/bin");
		path[3] = ft_strdup("/usr/sbin");
		path[4] = ft_strdup("/sbin");
		path[5] = ft_strdup("/opt/X11/bin");
		path[6] = ft_strdup("/usr/texbin");
		path[7] = NULL;
	}
	return (ft_duptab(path));
}
