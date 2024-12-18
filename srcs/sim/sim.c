/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:59 by luctan            #+#    #+#             */
/*   Updated: 2024/12/18 03:21:00 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_philo *philo)
{
	mutex_handle(&philo->fork1, LOCK);
	print_stat(FIRST_FORK, philo, 0);
	mutex_handle(&philo->fork2, LOCK);
	print_stat(SECOND_FORK, philo, 0);
	long_set(&phi)
}

void	wait_thread(t_table *table)
{
	while (!bool_get(&table->table_mtx, &table->threads_ok))
		;
} 

void	sim_start(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_threads(philo->table);
	while (!sim_end(philo->table))
	{
		if (get_bool(philo->full, true))
			break ;
		eat(philo);
		// sleep > status.
		print_stat(ASLEEP, philo, 0);
		r_usleep(philo->table->to_sleep, philo->table);
		think(philo);
	}
}

void	sim_init(t_table *table)
{
	int	i;

	i = -1;
	if (!table->nb_eat)
		return ;
	else if (table->nbrphil == 1)
		;
	else
	{
		while (++i < table->nbrphil)
			thread_handle(&table->philos[i].thread_id, sim_start,
				&table->philos[i], CREATE);
	}
	table->start = timeset(MS);
	bool_set(&table->table_mtx, &table->threads_ok, true);
	i = -1;
	while (table->nbrphil > ++i)
		thread_handle(&table->philos[i].id, NULL, NULL, JOIN);
}
