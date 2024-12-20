/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:17:43 by luctan            #+#    #+#             */
/*   Updated: 2024/12/20 04:27:15 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool perished(t_philo *philo)
{
	long	time;
	long	to_die;

	if (bool_get(&philo->philo_mtx, &philo->full))
		return (false);
	time = timeset(MS) - long_get(&philo->philo_mtx, &philo->last_meal);
	to_die = (philo->table->to_die / 1e3);
	if (time > to_die)
		return (true);
	return (false);
}

void	*sim_monitor(void *data)
{
	t_table	*table;
	int			i;

	table = (t_table *)data;
	while (!all_running(&table->table_mtx, &table->threads_count, table->nbrphil))
		;
	while (!sim_end(table))
	{
		i = -1;
		while (++i < table->nbrphil && !sim_end(table))
		{
			if (perished(table->philos + i))
			{
				bool_set(&table->table_mtx, &table->end, true);
				print_stat(DEAD, table->philos + i);
			}
		}
	}
	return (NULL);
}

void	fair_sys(t_philo *philo)
{
	if (philo->table->nbrphil % 2 == 0)
	{
		if (philo->id % 2 == 0)
			r_usleep(30, philo->table);
	}
	else
	{
		if (philo->id % 2)
			think(philo, true);
	}
}