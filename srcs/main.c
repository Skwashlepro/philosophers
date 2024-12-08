/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:41:19 by luctan            #+#    #+#             */
/*   Updated: 2024/11/20 22:16:06 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac != 6)
		exit_error("Invalid number of arguments");
	else if (ac == 6)
	{
		db_init(&table, av + 1);
		sim_init(&table);
	}
	return (0);
}
