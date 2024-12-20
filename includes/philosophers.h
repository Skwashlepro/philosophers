/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:36:49 by luctan            #+#    #+#             */
/*   Updated: 2024/12/20 04:27:09 by luctan           ###   ########.fr       */
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
# include <errno.h>
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

typedef enum e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_opcode;

typedef enum e_stat
{
	ASLEEP,
	EATING,
	THINKING,
	DEAD,
	FULL,
	FIRST_FORK,
	SECOND_FORK,
	}	t_stat;

typedef enum e_time
{
	SEC,
	MS,
	US,
}	t_time;

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
	t_fork		*fork1;
	t_fork		*fork2;
	pthread_t	thread_id;
	t_table		*table;
	t_mutex		philo_mtx;

}	t_philo;

struct s_table
{
	long		nbrphil;
	long		to_die;
	long		to_eat;
	long		to_sleep;
	long		nb_eat;
	long		start;
	long		threads_count;
	bool		end;
	bool		threads_ok;
	t_mutex		table_mtx;
	t_mutex		mtx_lock;
	t_mutex		prt_mtx;
	pthread_t	monitor;
	t_fork		*forks;
	t_philo		*philos;
};

void	db_free(t_table *table);
void	db_init(t_table *table, char **av);
void	exit_error(const char *str);
void	*my_malloc(size_t bytes);
void	mutex_handle(t_mutex *mutex, t_opcode code);
void	thread_handle(pthread_t *thread, void *(*foo)(void *), void *data,
			t_opcode opcode);
void	philo_init(t_table *table);
void	bool_set(t_mutex *mutex, bool *dest, bool value);
bool	bool_get(t_mutex *mutex, bool *value);
long	long_get(t_mutex *mutex, long *value);
void	long_set(t_mutex *mutex, long *dest, long value);
bool	sim_end(t_table *table);
void	wait_thread(t_table *table);
long	timeset(t_time time);
void	r_usleep(long usec, t_table *table);
void	print_stat(t_stat status, t_philo *philo);
void	sim_init(t_table *table);
void	*sim_monitor(void *data);
bool	all_running(t_mutex *mutex, long *threads, long nbrphil);
void	long_iterate(t_mutex *mtx, long	*nb);
void	think(t_philo *philo, bool bef);
void	fair_sys(t_philo *philo);

#endif