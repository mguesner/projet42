/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:45:18 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 11:17:30 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <libft.h>

static void	ft_put_error(char *str, char *error)
{
	write(2, "cd: ", 4);
	write(2, error, ft_strlen(error));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void		ft_error_cd(char *str)
{
	if (access(str, F_OK) == -1)
		ft_put_error(str, "no such file or directory: ");
	else if (!ft_isdir(str))
		ft_put_error(str, "not a directory: ");
	else if (access(str, X_OK) == -1)
		ft_put_error(str, "permission denied: ");
	else
		ft_put_error(str, "unknow error: ");
}
