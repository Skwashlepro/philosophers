/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:53:17 by luctan            #+#    #+#             */
/*   Updated: 2024/11/12 23:16:12 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	db_check(t_table *table)
{
	if (table->nbrphil <= 0)
		return (1);
	return (0);
}

void	init_db(t_table *table)
{
	ft_memset(table, 0, sizeof(t_table));
}

void	atoi_struct(t_table *table, char **av)
{
	table->nbrphil = ft_atol(av[0]);
	table->to_die = ft_atol(av[1]);
	table->to_eat = ft_atol(av[2]);
	table->to_sleep = ft_atol(av[3]);
	table->nb_eat = ft_atol(av[4]);
}

int	db_init(t_table *table, char **av)
{
	init_db(table);
	atoi_struct(table, av);
	if (db_check(table))
		return (1);
	return (0);
}
