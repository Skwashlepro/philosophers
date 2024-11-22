/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:45:56 by luctan            #+#    #+#             */
/*   Updated: 2024/11/21 23:39:23 by luctan           ###   ########.fr       */
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

long	timeset(t_time time)
{
	struct timeval	tval;

	if (gettimeofday(&tval, NULL))
		error_exit("getting time of day failed\n");
	if (SEC == time)
		return (tval.tv_sec + (tval.tv_usec * 100000));
	if (MS == time)
		return ((tval.tv_sec * 1000) + (tval.tv_usec / 1000));
	if (US == time)
		return ((tval.tv_sec * 100000) + tval.tv_usec);
	else
		exit_error("time enum invalid\n");
	return (4242);
}