/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 15:59:07 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/16 16:48:23 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	ft_option(char **arg, char option[2], int *i)
{
	int		j;

	while (arg[*i] && arg[*i][0] == '-')
	{
		j = 1;
		while (arg[*i][j] == 'n' || arg[*i][j] == 'e' || arg[*i][j] == 'E')
		{
			if (arg[*i][j] == 'n')
				option[0] = 1;
			else if (arg[*i][j] == 'e')
				option[1] = 0;
			else if (arg[*i][j] == 'E')
				option[1] = 1;
			j++;
		}
		if (!arg[*i][j])
			*i = (*i) + 1;
		else
			break ;
	}
}

static int	ft_check(char c)
{
	if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'c')
		return (1);
	else if (c == 'e')
		ft_putchar(27);
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'n')
		ft_putchar('\n');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else
		ft_putchar(c);
	return (0);
}

static void	ft_echap(char **arg, int i)
{
	int		j;

	while (arg[i])
	{
		j = 0;
		while (arg[i][j])
		{
			if (arg[i][j] == '\\')
			{
				j++;
				if (ft_check(arg[i][j]))
					return ;
			}
			else
				ft_putchar(arg[i][j]);
			j++;
		}
		if (arg[i])
			ft_putchar(' ');
		i++;
	}
}

static void	ft_normal(char **arg, int i)
{
	while (arg[i])
	{
		ft_putstr(arg[i]);
		i++;
		if (arg[i])
			ft_putchar(' ');
	}
}

int			ft_echo(char **arg)
{
	char	option[2];
	int		i;

	i = 1;
	option[0] = 0;
	option[1] = 0;
	ft_option(arg, option, &i);
	if (!option[1])
		ft_echap(arg, i);
	else
		ft_normal(arg, i);
	if (!option[0])
		ft_putendl("");
	return (1);
}
