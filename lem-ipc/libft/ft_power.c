/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguesner <mguesner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 08:17:31 by mguesner          #+#    #+#             */
/*   Updated: 2014/04/25 08:46:38 by mguesner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_power(int n, int a)
{
	if (n == 0)
		return (1);
	return (a * ft_power(n - 1, a));
}
