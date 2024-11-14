/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:33:24 by luctan            #+#    #+#             */
/*   Updated: 2024/11/14 21:33:39 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	mutex_error(int status, t_opcode code)
{
	if (status == 0)
		return ;
	else if (EINVAL == status && (LOCK == code || UNLOCK == code))
		exit_error("Operation code value invalid from mutex\n");
	else if (EINVAL == status && INIT == code)
		exit_error("The value from attr is invalid\n");
	else if (EDEADLK == status)
		exit_error("Deadlock error\n");
	else if (EPERM == status)
		error_exit("This thread does not hold a lock on mutex\n");
	else if (ENOMEM == status)
		error_exit("Not enough memory left for a new thread\n");
	else if (EBUSY == status)
		error_exit("Mutex is locked\n");
}

void	mutex_handle(t_mutex *mutex, t_opcode code)
{
	if (LOCK == code)
		mutex_error(pthread_mutex_lock(mutex), code);
	if (UNLOCK == code)
		mutex_error(pthread_mutex_unlock(mutex), code);
	if (DESTROY == code)
		mutex_error(pthread_mutex_destroy(mutex), code);
	if (INIT == code)
		mutex_error(pthread_mutex_init(mutex, NULL), code);
	else
		error_exit("Wrong opcode for mutex handling\n");
}
