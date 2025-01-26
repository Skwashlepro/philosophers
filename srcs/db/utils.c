/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:45:56 by luctan            #+#    #+#             */
/*   Updated: 2025/01/26 18:50:07 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	inputchk(char **av)
{
	if (ft_atol2(av[1]) == -1)
		return (1);
	if (ft_atol2(av[2]) == -1)
		return (1);
	if (ft_atol2(av[3]) == -1)
		return (1);
	if (ft_atol2(av[4]) == -1)
		return (1);
	if (av[5])
		if (ft_atol2(av[5]) == -1)
			return (1);
	return (0);
}

void	*my_malloc(size_t bytes)
{
	void	*all;

	all = malloc(bytes);
	if (!all)
		return (printf("MEMORY ERROR\n"), NULL);
	return (all);
}

long	timeset(t_time time)
{
	struct timeval	tval;

	if (gettimeofday(&tval, NULL))
		printf("getting time of day failed\n");
	else if (SEC == time)
		return (tval.tv_sec + (tval.tv_usec * 1000000));
	else if (MS == time)
		return ((tval.tv_sec * 1000) + (tval.tv_usec / 1000));
	else if (US == time)
		return ((tval.tv_sec * 1000000) + tval.tv_usec);
	else
		printf("time enum invalid\n");
	return (4242);
}
