/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleans.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:15:40 by luctan            #+#    #+#             */
/*   Updated: 2025/01/26 18:50:26 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	db_free(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++i < table->nbrphil)
	{
		philo = table->philos + i;
		mutex_handle(&philo->philo_mtx, DESTROY);
	}
	mutex_handle(&table->prt_mtx, DESTROY);
	mutex_handle(&table->table_mtx, DESTROY);
	free(table->forks);
	free(table->philos);
}
