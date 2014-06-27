/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 17:37:56 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/05 14:06:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_cpyenv(char **env)
{
	int		i;
	char	**cpy;

	i = 0;
	while (env[i])
		i++;
	cpy = (char **)ft_memalloc((i + 1) * sizeof(char *));
	cpy[i] = NULL;
	i--;
	while (i >= 0)
	{
		cpy[i] = ft_strdup(env[i]);
		i--;
	}
	return (cpy);
}
