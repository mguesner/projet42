/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_option_client_human.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:25:12 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:25:17 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static int		st_parse_option(char **av, int *n, int *p)
{
	if (!av[2][0] || !av[4][0])
		return (-1);
	if (strcmp(av[1], "-n") == 0)
		*n = 2;
	else if (strcmp(av[1], "-p") == 0)
		*p = 2;
	else
		return (-1);
	if (strcmp(av[3], "-n") == 0 && *n == 0)
		*n = 4;
	else if (strcmp(av[3], "-p") == 0 && *p == 0)
		*p = 4;
	else
		return (-1);
	return (0);
}

static int		st_parse_option_h(char **av, int *n, int *p, int *h)
{
	if (strcmp(av[1], "-n") == 0)
		*n = 2;
	else if (strcmp(av[1], "-p") == 0)
		*p = 2;
	else if (strcmp(av[1], "-h") == 0)
		*h = 2;
	else
		return (-1);
	if (strcmp(av[3], "-n") == 0 && *n == 0)
		*n = 4;
	else if (strcmp(av[3], "-p") == 0 && *p == 0)
		*p = 4;
	else if (strcmp(av[3], "-h") == 0 && *h == 0)
		*h = 4;
	else
		return (-1);
	if (strcmp(av[5], "-n") == 0 && *n == 0)
		*n = 6;
	else if (strcmp(av[5], "-p") == 0 && *p == 0)
		*p = 6;
	else if (strcmp(av[5], "-h") == 0 && *h == 0)
		*h = 6;
	else
		return (-1);
	return (0);
}

int				ft_parse_option_human(int ac, char **av, t_env *e)
{
	int			n;
	int			p;
	int			h;

	n = 0;
	p = 0;
	h = 0;
	if (ac == 5 && st_parse_option(av, &n, &p) == -1)
		return (-1);
	else if (ac == 7 && st_parse_option_h(av, &n, &p, &h) == -1)
		return (-1);
	else if ((ac != 7 && ac != 5) || !av[2][0] || !av[4][0])
		return (-1);
	if ((e->port = atoi(av[p])) == 0)
		return (-1);
	if (ac == 5)
		e->host = gethostbyname("localhost");
	else
	{
		printf("%s\n", av[h]);
		e->host = gethostbyname(av[h]);
	}
	e->team = strdup(av[n]);
	return (0);
}
