/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:36:49 by luctan            #+#    #+#             */
/*   Updated: 2024/11/12 23:11:33 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"
// Reset
# define RESET "\033[0m"

// Bold colors
# define BOLD_BLACK   "\033[1;30m"
# define BOLD_RED     "\033[1;31m"
# define BOLD_GREEN   "\033[1;32m"
# define BOLD_YELLOW  "\033[1;33m"
# define BOLD_BLUE    "\033[1;34m"
# define BOLD_MAGENTA "\033[1;35m"
# define BOLD_CYAN    "\033[1;36m"
# define BOLD_WHITE   "\033[1;37m"

typedef pthread_mutex_t	t_mutex;

typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mutex	fork;
	int		fork_id;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			meals;
	bool		full;
	long		last_meal;
	t_fork		l_fork;
	t_fork		r_fork;
	pthread_t	thread_id;
	t_table		*table;

}	t_philo;

struct s_table
{
	long		nbrphil;
	long		to_die;
	long		to_eat;
	long		to_sleep;
	long		nb_eat;
	long		start;
	bool		end;
	t_fork		*forks;
	t_philo		*philos;
};

void	db_free(t_table *table);
int		db_init(t_table *table, char **av);
void	exit_error(const char *str);

#endif