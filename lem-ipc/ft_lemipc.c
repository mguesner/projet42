/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemipc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 13:41:47 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/29 16:36:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"
#include <sys/shm.h>
#include <libft.h>
#include <sys/sem.h>

void	ft_lemipc(int team, key_t key)
{
	int		sem_id;
	int		mem_id;
	void	*shared;

	if ((mem_id = shmget(key, SIZE * SIZE, IPC_CREAT | IPC_EXCL | 0666)) >= 0)
	{
		if ((shared = shmat(mem_id, NULL, 0)) == (void *)-1)
			ft_perror("shmat");
		ft_memset(shared, '.', SIZE * SIZE);
	}
	else if ((mem_id = shmget(key, SIZE * SIZE, 0666)) < 0)
		ft_perror("shmget");
	if ((shared = shmat(mem_id, NULL, 0)) == (void *)-1)
		ft_perror("shmat");
	if ((sem_id = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666)) >= 0)
	{
		if (semctl(sem_id, 0, SETVAL, 1) < 0)
			ft_perror("semctl");
	}
	if ((sem_id = semget(key, 1, 0666)) < 0)
		ft_perror("semget");
	ft_initplay(team, shared, sem_id);
	ft_printf("team : %d win!\n", team);
	shmctl(mem_id, IPC_RMID, 0);
	semctl(sem_id, 0, IPC_RMID, 0);
}
