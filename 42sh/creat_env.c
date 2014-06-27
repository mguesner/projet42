/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:16:54 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 13:38:02 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_sh.h"
#include <unistd.h>

static char	**init(void)
{
	int			i;
	char		**env;
	extern char	**environ;

	i = 0;
	while (environ[i])
		i++;
	if (!(env = (char **)ft_memalloc((i + 2) * sizeof(char *))))
		return (NULL);
	return (env);
}

static void	ft_done(int	j, int i, char **env)
{
	char	*buff;

	if (!j)
	{
		buff = getcwd(NULL, 1024);
		env[i] = ft_strjoin("PWD=", buff);
		ft_strdel(&buff);
		i++;
	}
	env[i] = NULL;
}

char		**creat_env(void)
{
	extern char	**environ;
	char		**env;
	char		*buff;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!(env = init()))
		return (NULL);
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], "PWD", 3))
		{
			buff = getcwd(NULL, 1024);
			env[i] = ft_strjoin("PWD=", buff);
			ft_strdel(&buff);
			j = 1;
		}
		else
			env[i] = ft_strdup(environ[i]);
		i++;
	}
	ft_done(j, i, env);
	return (env);
}
