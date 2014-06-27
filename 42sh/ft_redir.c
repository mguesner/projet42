/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 13:22:47 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/26 10:35:24 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <fcntl.h>
#include <unistd.h>
#include <libft.h>

static int	ft_redir2(int redir, char **cmd, int i)
{
	int		fd;

	if (redir)
	{
		if (redir == 1)
		{
			if (((fd = open(cmd[i + 1], O_RDONLY)) == -1))
				return (ft_file_error(cmd[i + 1]));
			dup2(fd, 0);
		}
		else if (redir == 2 || redir == 3)
		{
			if ((redir == 2
						&& (fd = open(cmd[i + 1], O_WRONLY
								| O_CREAT | O_TRUNC, 0644))
							== -1) || (redir == 3
								&& (fd = open(cmd[i + 1], O_WRONLY | O_CREAT
										| O_APPEND, 0644))
							== -1))
				return (ft_file_error(cmd[i + 1]));
			dup2(fd, 1);
		}
		cmd[i] = NULL;
	}
	return (1);
}

static void	ft_preredir(char **cmd)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	if (cmd[0] && *(cmd[0]) == '<')
	{
		tmp = cmd[0];
		if (cmd[1])
		{
			tmp2 = cmd[1];
			i = 2;
			while (cmd[i])
			{
				cmd[i - 2] = cmd[i];
				i++;
			}
			cmd[i - 2] = tmp;
			cmd[i - 1] = tmp2;
		}
	}
}

int			ft_redir(char **cmd)
{
	int		i;
	int		redir;

	ft_preredir(cmd);
	i = -1;
	redir = 1;
	while (cmd[++i])
	{
		if (*(cmd[i]) == '<')
			redir = ft_redir2(1, cmd, i);
		else if (*(cmd[i]) == '>' && *(cmd[i] + 1) != '>')
			redir = ft_redir2(2, cmd, i);
		else if (*(cmd[i]) == '>' && *(cmd[i] + 1) == '>')
			redir = ft_redir2(3, cmd, i);
	}
	return (redir);
}
