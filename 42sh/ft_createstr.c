/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 17:22:43 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/26 17:26:32 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_createstr(char c, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(n);
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
