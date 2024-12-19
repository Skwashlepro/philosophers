/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:02:28 by luctan            #+#    #+#             */
/*   Updated: 2024/12/19 20:15:00 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	r_usleep(long usec, t_table *table)
{
	long	start;
	long	cur_time;
	long	to_sleep;

	start = timeset(US);
	while (timeset(US) - start < usec)
	{
		if (sim_end(table))
			break ;
		cur_time = timeset(US) - start;
		to_sleep = usec - cur_time;
		if (cur_time > 1000)
			usleep(to_sleep / 2);
		else
			while (timeset(US) - start < usec)
				;
	}
}

void	print_stat(t_stat status, t_philo *philo, bool debug)
{
	long	elapsed;

	elapsed = timeset(MS);
	if (philo->full)
		return ;
	mutex_handle(&philo->table->prt_mtx, LOCK);
	if (debug)
		;
	else
	{
		if ((status == FIRST_FORK || status == SECOND_FORK) && !sim_end(philo->table))
			printf("%ld\n %d took a fork\n", elapsed, philo->id);
		else if (status == EATING)
			printf("%ld\n %d is eating\n", elapsed, philo->id);
		else if (status == ASLEEP)
			printf("%ld\n %d is asleep\n", elapsed, philo->id);
		else if (status == THINKING)
			printf("%ld\n %d is thinking\n", elapsed, philo->id);
		else if (status == DEAD)
			printf("%ld\n %d perished\n", elapsed, philo->id);
	}
	mutex_handle(&philo->table->prt_mtx, UNLOCK);
}