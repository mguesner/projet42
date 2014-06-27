/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/10 14:32:49 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/10 14:37:32 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	**ft_stock(char **env, int mode)
{
	static char	**save_env = NULL;

	if (!mode)
		save_env = env;
	else
		return (save_env);
	return (NULL);
}
