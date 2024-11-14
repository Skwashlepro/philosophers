/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:45:56 by luctan            #+#    #+#             */
/*   Updated: 2024/11/14 21:33:14 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(char **nb)
{
	long	n;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	n = 0;
	while (nb[1][i] == 32 || (nb[1][i] >= 9 && nb[1][i] <= 13))
		i++;
	if (nb[1][i] == '+' || nb[1][i] == '-')
	{
		if (nb[1][i] == '-')
			sign = -1;
		i++;
	}
	while (nb[1][i] && nb[1][i] >= '0' && nb[1][i] <= '9')
	{
		if (n > (LONG_MAX - (nb[1][i] - '0')) / 10)
			nb_error(nb);
		n = n * 10 + (nb[1][i++] - '0');
	}
	return (n * sign);
}

void	*my_malloc(size_t bytes)
{
	void	*all;

	all = malloc(bytes);
	if (!all)
		exit_error("MEMORY ERROR\n");
	return (all);
}
