/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/07 11:15:05 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/12 15:38:20 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"
#include <libft.h>

static void		opt2(t_env *e, char **argv, int *i)
{
	t_list	*tmp;

	e->names = new_name(argv[*i]);
	tmp = e->names;
	while (argv[++*i] && *argv[*i] != '-' && (tmp->next = new_name(argv[*i])))
		tmp = tmp->next;
}

int				opt(char **argv, t_env *e)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (*argv[i] != '-')
			return (0);
		if (!ft_strcmp(argv[i], "-p") && i++)
			e->port = ft_atoi(argv[i++]);
		if (!ft_strcmp(argv[i], "-x") && i++)
			e->width = ft_atoi(argv[i++]);
		if (!ft_strcmp(argv[i], "-y") && i++)
			e->height = ft_atoi(argv[i++]);
		if (!ft_strcmp(argv[i], "-n") && i++ && *argv[i] != '-')
			opt2(e, argv, &i);
		if (!ft_strcmp(argv[i], "-c") && i++)
			e->nb = ft_atoi(argv[i++]);
		if (!ft_strcmp(argv[i], "-t") && i++)
			e->time = ft_atoi(argv[i++]);
	}
	return (1);
}
