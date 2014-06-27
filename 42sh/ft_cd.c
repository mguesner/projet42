/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:05:22 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:21:27 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <stdlib.h>
#include <libft.h>

static int	ft_error_option(char c)
{
	write(2, "42sh: cd: -", 12);
	write(2, &c, 1);
	write(2, ": invalid option\ncd: usage: cd [-L|-P] [dir]\n", 45);
	return (-1);
}

static int	ft_cd_option(char **tab, int i, int *mode)
{
	int		j;

	j = 1;
	while (tab[i][j] && (tab[i][j] == 'P' || tab[i][j] == 'L'))
	{
		if (tab[i][j] == 'P')
			*mode = 1;
		else
			*mode = 0;
		j++;
	}
	if (tab[i][j])
		return (ft_error_option(tab[i][j]));
	return (1);
}

static void	ft_do_chdir(char *pwd, char *oldpwd, char ***env, int mode)
{
	char	*buff;
	char	*tmp;
	int		i;

	if (!chdir(pwd))
	{
		ft_setenv(env, "OLDPWD", oldpwd);
		buff = getcwd(NULL, 1024);
		tmp = ft_strrchr(pwd, '/') ? ft_strrchr(pwd, '/') + 1 : pwd;
		if (!mode && ft_strcmp("..", pwd) && ft_strcmp(".", pwd)
				&& ft_strcmp(tmp, ft_strrchr(buff, '/') + 1))
		{
			i = ft_strlen(buff);
			while (i > 0 && buff[i] != '/')
				i--;
			ft_putendl(&buff[i]);
			ft_strcpy(buff + i + 1, tmp);
		}
		ft_setenv(env, "PWD", buff);
		ft_strdel(&buff);
	}
	else
		ft_error_cd(pwd);
}

static int	ft_cd2(char **tab, char ***env, int mode)
{
	if (!tab[0])
	{
		if (!ft_getenv("HOME", *env))
		{
			write(2, "42sh: cd: HOME not set\n", 23);
			return (-1);
		}
		ft_do_chdir(ft_getenv("HOME", *env),
					ft_getenv("PWD", *env), env, mode);
	}
	else if (!ft_strcmp(tab[0], "-"))
	{
		if (!ft_getenv("OLDPWD", *env))
		{
			write(2, "42sh: cd: OLDPWD not set\n", 25);
			return (-1);
		}
		ft_do_chdir(ft_getenv("OLDPWD", *env),
					ft_getenv("PWD", *env), env, mode);
		ft_putendl(ft_getenv("PWD", *env) + 13);
	}
	else
		ft_do_chdir(tab[0], ft_getenv("PWD", *env), env, mode);
	return (0);
}

int			ft_cd(char **tab, char ***env)
{
	int		i;
	int		ret;
	int		mode;

	i = 0;
	mode = 0;
	ret = 1;
	while (tab[++i] && tab[i][0] == '-')
	{
		if (!tab[i][1])
		{
			ret = ft_cd2(tab + i, env, 1);
			break ;
		}
		else if (tab[i][1] == '-' && !tab[i][2])
		{
			ret = ft_cd2(tab + i + 1, env, mode);
			break ;
		}
		if ((ret = ft_cd_option(tab, i, &mode)) < 0)
			break ;
	}
	ret = (ret != 1 ? ret : ft_cd2(tab + i, env, mode));
	return (ret);
}
