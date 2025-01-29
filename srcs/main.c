/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:41:19 by luctan            #+#    #+#             */
/*   Updated: 2025/01/29 23:33:27 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if ((ac == 6 || ac == 5))
	{
		if (inputchk(av))
			return (printf("Invalid arguments\n"), 1);
		db_init(&table, av + 1);
		sim_init(&table);
		db_free(&table);
	}
	else
		printf("Invalid number of arguments\n");
	return (0);
}
