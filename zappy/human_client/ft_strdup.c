/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 17:56:12 by mdarty            #+#    #+#             */
/*   Updated: 2014/02/02 08:15:41 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

char	*ft_strdup(const char *s1)
{
	int		size;
	int		i;
	char	*str;

	i = 0;
	size = 0;
	if (s1)
		size = strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
