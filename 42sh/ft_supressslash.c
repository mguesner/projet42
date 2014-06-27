/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supressslash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 14:51:10 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/10 13:17:38 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_supressslash(char **arg)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (arg[i])
	{
		k = 0;
		j = 0;
		while (arg[i][j] && arg[i][j + k])
		{
			arg[i][j] = arg[i][j + k];
			if (arg[i][j] == '\\')
			{
				k++;
				arg[i][j] = arg[i][j + k];
			}
			j++;
		}
		arg[i][j] = 0;
		i++;
	}
}
