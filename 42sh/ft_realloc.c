/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 14:36:15 by mguesner          #+#    #+#             */
/*   Updated: 2014/02/25 10:52:34 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_realloc(char *str, int size)
{
	char	*ret;

	ret = (char *)malloc(size * sizeof(char));
	ft_strcpy(ret, str);
	ft_strdel(&str);
	return (ret);
}
