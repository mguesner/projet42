/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/26 13:15:44 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/03 15:17:20 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <libft.h>
#include <unistd.h>

static void	ft_put_error(char *str, char *error)
{
	write(2, "42sh: ", 7);
	write(2, error, ft_strlen(error));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

int			ft_file_error(char *str)
{
	if (access(str, F_OK) == -1)
		ft_put_error(str, "no such file or directory: ");
	else if (access(str, W_OK) == -1 || access(str, R_OK) == -1)
		ft_put_error(str, "permission denied: ");
	else
		ft_put_error(str, "unknow error: ");
	return (0);
}
