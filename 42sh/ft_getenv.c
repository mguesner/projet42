/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:32:00 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/25 16:35:16 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_getenv(char *str, char **env)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (env[i])
	{
		if (!ft_strncmp(env[i], str, len))
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}
