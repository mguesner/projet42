/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocomplete2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:15:05 by nguezell          #+#    #+#             */
/*   Updated: 2014/03/27 11:16:58 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

void	ft_add_rep(t_list **lst, char *dirname)
{
	DIR				*dir;
	struct dirent	*directory;

	if ((dir = opendir(dirname)) != NULL)
	{
		while ((directory = readdir(dir)))
			ft_add_node(lst, directory->d_name);
		closedir(dir);
	}
	(*lst)->flag = 0;
}

void	ft_add_all_tolist(t_list **lst, char *dirname)
{
	DIR				*dir;
	struct dirent	*directory;

	if ((dir = opendir(dirname)) != NULL)
	{
		while ((directory = readdir(dir)))
			ft_add_node(lst, directory->d_name);
		closedir(dir);
	}
	ft_add_node(lst, "cd");
	ft_add_node(lst, "exit");
	ft_add_node(lst, "setenv");
	ft_add_node(lst, "unsetenv");
	ft_add_node(lst, "echo");
	ft_add_node(lst, "env");
	ft_add_node(lst, "fg");
}

void	ft_complete_cmd(char **line, char **path, t_list **lst)
{
	int		i;

	i = 0;
	while (path[i])
	{
		ft_add_tolist(lst, path[i], *line);
		i++;
	}
	i = ft_strlen(*line);
	if (!ft_strncmp("cd", *line, i))
		ft_add_node(lst, "cd");
	if (!ft_strncmp("exit", *line, i))
		ft_add_node(lst, "exit");
	if (!ft_strncmp("setenv", *line, i))
		ft_add_node(lst, "setenv");
	if (!ft_strncmp("unsetenv", *line, i))
		ft_add_node(lst, "unsetenv");
	if (!ft_strncmp("echo", *line, i))
		ft_add_node(lst, "echo");
	if (!ft_strncmp("env", *line, i))
		ft_add_node(lst, "env");
	if (!ft_strncmp("fg", *line, i))
		ft_add_node(lst, "fg");
}

void	ft_allcmd(t_list **lst, char **path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		ft_add_all_tolist(lst, path[i]);
		i++;
	}
}

char	*ft_getwords(char *line, int *slash)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	while (i > 0 && line[i - 1] != ' ')
	{
		if (line[i] == '/')
			(*slash)++;
		i--;
	}
	str = ft_strdup(line + i);
	return (str);
}
