/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsupressslash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 13:26:47 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/10 13:28:42 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strsupressslash(char *str)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (str[i] && str[i + k])
	{
		str[i] = str[i + k];
		if (str[i] == '\\')
		{
			k++;
			str[i] = str[i + k];
		}
		i++;
	}
	str[i] = 0;
}
