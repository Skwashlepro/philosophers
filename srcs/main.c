/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:41:19 by luctan            #+#    #+#             */
/*   Updated: 2024/11/12 23:15:30 by luctan           ###   ########.fr       */
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
		if (db_init(&table, av + 1))
			exit_error("Invalid arguments : No Philosophers");
		
	}
	return (0);
}
