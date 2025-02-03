/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:36:48 by luctan            #+#    #+#             */
/*   Updated: 2025/02/03 23:32:52 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	assign_forks(t_philo *philo, t_fork *forks, int i)
{
	int	philo_nbr;

	philo_nbr = philo->table->nbrphil;
	philo->fork1 = &forks[(i + 1) % philo_nbr];
	philo->fork2 = &forks[i];
	if ((philo->id % 2) == 0)
	{
		philo->fork1 = &forks[i];
		philo->fork2 = &forks[(i + 1) % philo_nbr];
	}
}

void	philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	while (++i < table->nbrphil)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals = 0;
		philo->last_meal = 0;
		philo->table = table;
		mutex_handle(&philo->philo_mtx, INIT);
		assign_forks(philo, table->forks, i);
	}
}
