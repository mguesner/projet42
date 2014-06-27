/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocomplete3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguezell <nguezell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:17:07 by nguezell          #+#    #+#             */
/*   Updated: 2014/03/27 13:10:41 by nguezell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <dirent.h>
#include <stdlib.h>

int		ft_countword(char *line)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (line[i])
	{
		if (line[i] == ' ' && nb > 0)
			nb++;
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i])
			nb++;
		while (line[i] && line[i] != ' ')
		{
			if (line[i] == '|')
				nb = 0;
			i++;
		}
	}
	return (nb);
}

void	ft_delnode(t_list **node)
{
	free((*node)->content);
	free((*node));
}

char	*ft_malloc_slash(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isop(str[i]) || str[i] == ' ')
			i++;
		i++;
	}
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	return (tmp);
}

char	*ft_str_spe_dup(char *str)
{
	char	*buf;
	int		i;
	int		j;

	buf = ft_malloc_slash(str);
	i = 0;
	j = 0;
	while (str[j])
	{
		if (ft_isop(str[j]) || str[i] == ' ')
		{
			buf[i] = '\\';
			i++;
			buf[i] = str[j];
		}
		else
			buf[i] = str[j];
		i++;
		j++;
	}
	buf[i] = '\0';
	return (buf);
}
