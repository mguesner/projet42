/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 16:16:05 by mguesner          #+#    #+#             */
/*   Updated: 2014/03/19 13:50:47 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"
#include <unistd.h>
#include <libft.h>

void	ft_add_job(pid_t job, char *cmd)
{
	t_list	*tmp;

	if (!g_e.job)
	{
		g_e.job = ft_create_elem(cmd, 0);
		g_e.job->job = job;
	}
	else
	{
		tmp = ft_create_elem(cmd, 0);
		tmp->job = job;
		tmp->next = g_e.job;
		g_e.job = tmp;
	}
}
