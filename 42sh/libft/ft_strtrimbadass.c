/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimbadass.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:10:13 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/10 11:27:32 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtrimbadass(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_isblank(str[i]))
		i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	i--;
	while (i >= 0 && ft_isblank(str[i]) && (i < 1 || str[i - 1] != '\\'))
	{
		i--;
		j--;
	}
	j = (j >= 0 ? j : 0);
	str[j] = 0;
}
