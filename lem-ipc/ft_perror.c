/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/19 14:16:04 by mguesner          #+#    #+#             */
/*   Updated: 2014/05/19 14:32:07 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

void	ft_perror(char *str)
{
	fprintf(stderr, "Error : %s : %s\n", str, strerror(errno));
	exit(1);
}
