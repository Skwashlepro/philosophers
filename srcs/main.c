/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:41:19 by luctan            #+#    #+#             */
/*   Updated: 2025/01/24 20:14:57 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (inputchk(av))
		printf("Invalid arguments\n");
	else if ((ac == 6 || ac == 5))
	{
		db_init(&table, av + 1);
		sim_init(&table);
		db_free(&table);
	}
	else
		printf("Invalid number of argumentes\n");
	return (0);
}
