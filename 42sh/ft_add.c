/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 15:50:43 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:15:27 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_sh.h"

void	ft_add(char *str, int i, char c, int *size)
{
	int	j;

	j = ft_strlen(str);
	if (j + 1 > *size)
	{
		*size = *size * 2;
		str = ft_realloc(str, *size);
	}
	str[j + 1] = 0;
	while (j > i)
	{
		str[j] = str[j - 1];
		j--;
	}
	str[i] = c;
}
