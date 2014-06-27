/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocomplete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 12:09:00 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/27 13:07:21 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

void	ft_cut(char *word, char **way, char **find)
{
	int	i;

	i = 0;
	while (word[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (word[i] == '/')
			break ;
		i--;
	}
	*find = ft_strdup(word + i + 1);
	*way = (char *)ft_memalloc(sizeof(char) * (i + 1));
	ft_strncpy(*way, word, i + 1);
}

void	ft_absolute_path(char *word, t_list **lst)
{
	char	*way;
	char	*complete;

	way = NULL;
	complete = NULL;
	ft_cut(word, &way, &complete);
	ft_add_tolist(lst, way, complete);
	free(way);
	free(complete);
}

void	ft_try_depth(char *word, t_list **lst)
{
	char	*path;
	char	*complete;
	char	*tmp;

	path = NULL;
	tmp = NULL;
	complete = NULL;
	ft_cut(word, &tmp, &complete);
	path = ft_strjoin("./", tmp);
	ft_add_tolist(lst, path, complete);
	free(tmp);
	free(path);
	free(complete);
}

void	ft_complete_file(char **save, int slash, t_list **lst)
{
	if (*save[0] == '/')
		ft_absolute_path(*save, lst);
	else if (slash)
		ft_try_depth(*save, lst);
	else
		ft_add_tolist(lst, ".", *save);
}

t_list	*ft_autocomplete(char *line, char **path)
{
	int		word;
	char	*save;
	int		slash;
	t_list	*lst;

	lst = NULL;
	slash = 0;
	word = ft_countword(line);
	if (word != 0 && word != 2)
		save = ft_getwords(line, &slash);
	if (word == 1)
	{
		ft_complete_cmd(&save, path, &lst);
		free(save);
	}
	else if (word == 2)
		ft_add_rep(&lst, ".");
	else if (word > 2)
	{
		ft_complete_file(&save, slash, &lst);
		free(save);
	}
	else
		ft_allcmd(&lst, path);
	return (lst);
}
