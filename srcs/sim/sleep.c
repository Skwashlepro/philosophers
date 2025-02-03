/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:02:28 by luctan            #+#    #+#             */
/*   Updated: 2025/02/03 23:27:39 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	r_usleep(long usec, t_table *table)
{
	long	start;
	long	cur_time;
	long	to_sleep;

	start = timeset(US);
	if (start == -1)
		return ;
	while (timeset(US) - start < usec)
	{
		if (sim_end(table))
			break ;
		cur_time = timeset(US) - start;
		to_sleep = usec - cur_time;
		if (to_sleep > 1e3)
			usleep(to_sleep / 2);
		else
			while (timeset(US) - start < usec)
				;
	}
}

static long	elapsed(t_philo *philo)
{
	long	elap;

	elap = (timeset(MS) - philo->table->start);
	return (elap);
}

void	print_stat(t_stat status, t_philo *philo)
{
	if (philo->full)
		return ;
	mutex_handle(&philo->table->prt_mtx, LOCK);
	if ((status == FIRST_FORK || status == SECOND_FORK)
		&& !sim_end(philo->table))
		printf("%ld %d has taken a fork\n", elapsed(philo), philo->id);
	else if (status == EATING && !sim_end(philo->table))
		printf("%ld %d is eating\n", elapsed(philo), philo->id);
	else if (status == ASLEEP && !sim_end(philo->table))
		printf("%ld %d is sleeping\n", elapsed(philo), philo->id);
	else if (status == THINKING && !sim_end(philo->table))
		printf("%ld %d is thinking\n", elapsed(philo), philo->id);
	else if (status == DEAD)
		printf("%ld %d died\n", elapsed(philo), philo->id);
	mutex_handle(&philo->table->prt_mtx, UNLOCK);
}
