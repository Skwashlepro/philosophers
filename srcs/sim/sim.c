/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:59 by luctan            #+#    #+#             */
/*   Updated: 2024/12/19 20:42:02 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	eat(t_philo *philo)
{
	mutex_handle(&philo->fork1->fork, LOCK);
	print_stat(FIRST_FORK, philo, 0);
	mutex_handle(&philo->fork2->fork, LOCK);
	print_stat(SECOND_FORK, philo, 0);
	long_set(&philo->philo_mtx, &philo->last_meal, timeset(MS));
	philo->meals++;
	print_stat(EATING, philo, 0);
	r_usleep(philo->table->to_eat, philo->table);
	if (philo->table->nb_eat > 0
		&& philo->meals == philo->table->nb_eat)
		bool_set(&philo->philo_mtx, &philo->full, true);
	mutex_handle(&philo->fork1->fork, UNLOCK);
	mutex_handle(&philo->fork2->fork, UNLOCK);
}

static void	think(t_philo *philo)
{
	print_stat(THINKING, philo, 0);
}

void	*sim_start(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_thread(philo->table);
	long_iterate(&philo->table->table_mtx, &philo->table->threads_count);
	while (!sim_end(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		print_stat(ASLEEP, philo, 0);
		r_usleep(philo->table->to_sleep, philo->table);
		think(philo);
	}
	return (NULL);
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
	thread_handle(&table->monitor, sim_monitor, table, CREATE);	
	table->start = timeset(MS);
	bool_set(&table->table_mtx, &table->threads_ok, true);
	i = -1;
	while (table->nbrphil > ++i)
		thread_handle(&table->philos[i].thread_id, NULL, NULL, JOIN);
}
