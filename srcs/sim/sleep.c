/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:02:28 by luctan            #+#    #+#             */
/*   Updated: 2024/11/21 23:56:16 by luctan           ###   ########.fr       */
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
			usleep(usec / 2);
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
	thread_handle(&philo->thread_id, NULL, NULL, UNLOCK);
	if (status == FIRST_FORK)
		printf("%ld\n", "First fork taken");
	else if (status == SECOND_FORK)
		printf("%ls\n", "Second fork taken");
	thread_handle(&philo->thread_id, NULL, NULL, UNLOCK);
}