/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:30:18 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 15:19:28 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <libft.h>
#include <term.h>

void	ft_prompt(char **env)
{
	int		size_home;
	int		size_tmp;
	char	*tmp;
	char	*tmp2;

	tcsetattr(0, TCSADRAIN, &(g_e.termios_p));
	tmp = getcwd(NULL, 1024);
	size_tmp = ft_strlen(tmp) - 13;
	tmp2 = ft_getenv("HOME", env);
	ft_putstr("\033[32m");
	if (tmp2 && (size_home = ft_strlen(tmp2)) <= size_tmp
			&& !ft_strncmp(tmp2, tmp + 13, size_home))
	{
		write(1, "~", 1);
		g_e.prompt = size_tmp - size_home;
		write(1, tmp + 13 + size_home, g_e.prompt++);
	}
	else
	{
		g_e.prompt = size_tmp;
		write(1, tmp + 13, g_e.prompt);
	}
	ft_putstr("/ \033[31m<3<3<3 \033[0m");
	g_e.prompt = g_e.prompt + 9;
	ft_strdel(&tmp);
}
