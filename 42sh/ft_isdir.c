/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:57:39 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 11:18:49 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <sys/stat.h>

int	ft_isdir(char *path)
{
	struct stat	buf;

	if (!lstat(path, &buf) && S_ISDIR(buf.st_mode))
		return (1);
	return (0);
}
