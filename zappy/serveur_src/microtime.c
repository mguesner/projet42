/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microtime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/04 07:04:17 by mguesner          #+#    #+#             */
/*   Updated: 2014/06/09 09:36:02 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

unsigned long	microtime(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	return (unsigned long)((tv.tv_sec * 1000000ul) + tv.tv_usec);
}
