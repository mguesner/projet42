/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_human.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarty <mdarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 07:27:06 by mdarty            #+#    #+#             */
/*   Updated: 2014/06/24 07:27:07 by mdarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <md.h>

static void	st_cpy_end(t_player *player, int start)
{
	int		j;

	j = 0;
	while ((j + start) < player->ret_read)
	{
		player->read[j] = player->read[j + start];
		j++;
	}
	bzero(&player->read[j], BUFF_H - j + 1);
	player->ret_read = j;
}

static int	st_read_tmp_zero(t_player *player, t_env *e)
{
	int		i;

	i = 0;
	while (player->read[i])
	{
		while (player->read[i] && player->read[i] != '\n')
			i++;
		if (player->read[i] == '\n')
		{
			player->read[i] = '\0';
			ft_check_line(player, e);
			st_cpy_end(player, i + 1);
			i = 0;
		}
		else if (player->read[0])
			ft_check_line(player, e);
		else
			break ;
	}
	return (0);
}

static int	st_read_next(t_player *player, t_env *e, int tmp)
{
	int		i;

	i = 0;
	player->ret_read += tmp;
	player->read[player->ret_read] = '\0';
	while (player->read[i])
	{
		while (player->read[i] && player->read[i] != '\n')
			i++;
		if (player->read[i] == '\n')
		{
			player->read[i] = '\0';
			ft_check_line(player, e);
			st_cpy_end(player, i + 1);
			i = 0;
		}
		else
			break ;
	}
	return (1);
}

int			ft_read(t_player *player, t_env *e)
{
	int		tmp;

	tmp = read(player->sock, &player->read[player->ret_read],
							BUFF_H - player->ret_read - 1);
	if (tmp <= 0)
		return (st_read_tmp_zero(player, e));
	else
		return (st_read_next(player, e, tmp));
}
