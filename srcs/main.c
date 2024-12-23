/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:41:19 by luctan            #+#    #+#             */
/*   Updated: 2024/12/23 02:40:21 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 6 || ac == 5)
	{
		db_init(&table, av + 1);
		sim_init(&table);
		db_free(&table);
	}
	else
		exit_error("Invalid number of arguments");
	return (0);
}
