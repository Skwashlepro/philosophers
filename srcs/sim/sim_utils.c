/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 22:29:08 by luctan            #+#    #+#             */
/*   Updated: 2024/11/20 22:36:29 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	bool_set(t_mutex *mutex, bool *dest, bool value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}

bool	bool_get(t_mutex *mutex, bool *value)
{
	bool	ret;

	mutex_handle(mutex, LOCK);
	ret = *value;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

long	long_get(t_mutex *mutex, long *value)
{
	long	ret;

	mutex_handle(mutex, LOCK);
	ret = *value;
	mutex_handle(mutex, UNLOCK);
	return (ret);
}

long	long_set(t_mutex *mutex, long *dest, long value)
{
	mutex_handle(mutex, LOCK);
	*dest = value;
	mutex_handle(mutex, UNLOCK);
}
