/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:53:20 by luctan            #+#    #+#             */
/*   Updated: 2024/12/18 20:44:06 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thread_error(int status, t_opcode opcode)
{
	if (status == 0)
		return ;
	if (EAGAIN == status)
		exit_error("No resources for new thread \n");
	else if (EPERM == status)
		exit_error("Permission denied\n");
	else if (EINVAL == status && CREATE == opcode)
		exit_error("Value from attr is invalid\n");
	else if (EINVAL == status && (JOIN == opcode || DETACH == opcode))
		exit_error("Value from thread is invalid\n");
	else if (ESRCH == status)
		exit_error("No thread; thread id specified found");
	else if (EPERM == status)
		exit_error("Deadlock or thread called is the calling thread");
}

void	thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
	t_opcode opcode)
{
	if (opcode == CREATE)
		thread_error(pthread_create(thread, NULL, foo, data), opcode);
	else if (opcode == JOIN)
		thread_error(pthread_join(*thread, NULL), opcode);
	else if (opcode == DETACH)
		thread_error(pthread_detach(*thread), opcode);
	else
		exit_error("Wrong opcode for thread handling\n");
}
