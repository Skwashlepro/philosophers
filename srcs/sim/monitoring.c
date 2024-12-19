/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 20:17:43 by luctan            #+#    #+#             */
/*   Updated: 2024/12/19 20:51:40 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool perished(t_philo *philo)
{
	long	time;
	long	to_die;

	time = timeset(MS) - long_get(&philo->philo_mtx, &philo->last_meal);
	to_die = philo->table->to_die;
	if (time > to_die)
		return (true);
	return (false);
}

void	*sim_monitor(void *data)
{
	t_table	*table;
	int			i;

	table = (t_table *)data;
	while (all_running(&table->table_mtx, &table->threads_count, table->nbrphil))
		;
	while (!sim_end(table))
	{
		i = -1;
		while (++i < table->nbrphil)
		{
			if (perished(table->philos + i))
			{
				set_bool(&table->table_mtx, table->end, true);
				print_stat(DEAD, table->philos + i, 0);
			}
		}
	}
	return (NULL);
}