/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 14:03:23 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 15:08:49 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/sem.h>
#include "lemipc.h"

void	ft_lock(int sem_id)
{
	struct sembuf	sbuf;

	sbuf.sem_num = 0;
	sbuf.sem_op = -1;
	sbuf.sem_flg = 0;
	if (semop(sem_id, &sbuf, 1) < 0)
		ft_perror("lock");
}
