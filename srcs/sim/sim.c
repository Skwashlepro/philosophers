/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:18:59 by luctan            #+#    #+#             */
/*   Updated: 2025/02/03 21:34:44 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	wait_thread(philo->table);
	long_set(&philo->philo_mtx, &philo->last_meal, timeset(MS));
	long_iterate(&philo->table->table_mtx, &philo->table->threads_count);
	print_stat(FIRST_FORK, philo);
	while (!sim_end(philo->table))
		;
	return (NULL);
}

static void	eat(t_philo *philo)
{
	mutex_handle(&philo->fork1->fork, LOCK);
	print_stat(FIRST_FORK, philo);
	mutex_handle(&philo->fork2->fork, LOCK);
	print_stat(SECOND_FORK, philo);
	long_set(&philo->philo_mtx, &philo->last_meal, timeset(MS));
	philo->meals++;
	print_stat(EATING, philo);
	r_usleep(philo->table->to_eat, philo->table);
	if (philo->table->nb_eat > 0
		&& philo->meals == philo->table->nb_eat)
		bool_set(&philo->philo_mtx, &philo->full, true);
	mutex_handle(&philo->fork1->fork, UNLOCK);
	mutex_handle(&philo->fork2->fork, UNLOCK);
}

void	think(t_philo *philo, bool bef)
{
	long	eat_t;
	long	sleep_t;
	long	think_t;

	if (!bef)
		print_stat(THINKING, philo);
	if (philo->table->nbrphil % 2 == 0)
		return ;
	eat_t = philo->table->to_eat;
	sleep_t = philo->table->to_sleep;
	think_t = eat_t * 2 - sleep_t;
	if (think_t < 0)
		think_t = 0;
	r_usleep(think_t * 0.40, philo->table);
}

void	*sim_start(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	wait_thread(philo->table);
	long_set(&philo->philo_mtx, &philo->last_meal, timeset(MS));
	long_iterate(&philo->table->table_mtx, &philo->table->threads_count);
	fair_sys(philo);
	while (!sim_end(philo->table))
	{
		if (philo->full)
			break ;
		eat(philo);
		print_stat(ASLEEP, philo);
		r_usleep(philo->table->to_sleep, philo->table);
		think(philo, false);
	}
	return (NULL);
}

void	sim_init(t_table *table)
{
	int	i;

	i = -1;
	if (table->nb_eat == 0)
		return ;
	if (table->nbrphil == 1)
		thread_handle(&table->philos[0].thread_id, one_philo,
			&table->philos[0], CREATE);
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
	bool_set(&table->table_mtx, &table->end, true);
	thread_handle(&table->monitor, NULL, NULL, JOIN);
}