/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:53:17 by luctan            #+#    #+#             */
/*   Updated: 2024/11/14 22:06:26 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_db(t_table *table)
{
	int	i;

	i -1;
	table->end = false;
	table->philos = my_malloc(sizeof(t_philo) * table->nbrphil);
	table->forks = my_malloc(sizeof(t_fork) * table->nbrphil);
	while (++i < table->nbrphil)
	{
		mutex_handle(&table->forks[i], INIT);
		table->forks[i].fork_id = i;
	}
	philo_init(table);
}

static long	ft_atol2(const char *nb)
{
	long	n;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	n = 0;
	while (nb[i] == 32 || (nb[i] >= 9 && nb[i] <= 13))
		i++;
	if (nb[i] == '+' || nb[i] == '-')
	{
		if (nb[i] == '-')
			exit_error("Invalid parameters\n");
		i++;
	}
	while (nb[i] && nb[i] >= '0' && nb[i] <= '9')
	{
		if (n > (LONG_MAX - (nb[i] - '0')) / 10)
			exit_error("Invalid parameters\n");
		n = n * 10 + (nb[i++] - '0');
	}
	return (n * sign);
}

static void	atol_struct(t_table *table, char **av)
{
	table->nbrphil = ft_atol2(av[0]);
	table->to_die = ft_atol2(av[1]) * 1e3;
	table->to_eat = ft_atol2(av[2]) * 1e3;
	table->to_sleep = ft_atol2(av[3]) * 1e3;
	if (av[4])
		table->nb_eat = ft_atol2(av[4]);
	else
		table->nb_eat = -1;
}

int	db_init(t_table *table, char **av)
{
	check_input(av);
	init_db(table);
	atol_struct(table, av);
	return (0);
}
