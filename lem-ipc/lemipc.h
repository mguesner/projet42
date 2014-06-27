/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemipc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/29 13:40:06 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/31 17:11:45 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIPC_H
# define LEMIPC_H

# include <sys/ipc.h>

# define SIZE 10

int		ft_isnum(char *str);
void	ft_lemipc(key_t key, int team);
void	ft_perror(char *str);
void	ft_initplay(int team, void *shared, int sem_id);
void	ft_play(int x[2], int team, char *map, int sem_id);
int		ft_alone(char *map, int team, int x[2], int sem_id);
void	ft_death(char *map, int x[2], int sem_id, int team);
void	ft_lock(int sem_id);
void	ft_unlock(int sem_id);
void	ft_move(char *map, int x[2], int team);
void	ft_putmap(char *map);
void	ft_init(void);
int		ft_refresh(char *map);
void	ft_legend(void);

#endif
