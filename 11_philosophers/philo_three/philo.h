/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 01:50:02 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/30 20:46:17 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <semaphore.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

# define WRONG_NUM_ARGS	"Wrong number of arguments\n"

# define MAL_ERROR	"malloc funcrion error. Terminating program...\n"

# define WRONG_ARG		"Wrong argument. Terminating program...\n"

# define MUTEX_INIT_ERR	"pthread_mutex_init error. Terminating program...\n"

# define PTHREAD_JOIN_ERR	"pthread_join error. Terminating program...\n"

# define MUTEX_LOCK_ERR	"pthread_mutex_lock error. Terminating program...\n"

# define MUTEX_UNLOCK_ERR "pthread_mutex_unlock error.Terminating program...\n"

# define SEM_INIT_ERR "sem_init error. Terminating program...\n"

# define SEM_WAIT_ERR "sem_wait error. Terminating program...\n"

# define SEM_POST_ERR "sem_post error. Terminating program...\n"

# define SEM_DESTR_ERR "sem_destroy error. Terminating program...\n"

# define USAGE1	"Usage:\n./philo_one arg1 arg2 arg3 arg4 arg5(optional)\n"

# define USAGE2 "Arguments are:\narg1 - number_of_philosophers ( >= 1 )\n"

# define USAGE3 "arg2 - time_to_die (ms, > 0, arg2 > arg3)\n"

# define USAGE4 "arg3 - time_to_eat (ms, > 0, arg2 > arg3)\n"

# define USAGE5 "arg4 - time_to_sleep (ms, > 0)\n"

# define USAGE6 "arg5 - number_of_times_each_philo_must_eat ( >= 0 ) (opt)\n"

# define PHILO_EAT " is eating\n"

# define PHILO_SLEEP " is sleeping\n"

# define PHILO_THINKING " is thinking\n"

# define PHILO_TAKE_FORK " has taken a fork\n"

# define PHILO_DEAD " died\n"

double					g_ts_simulation_start;
int						g_all_alive;
long long int			g_number_of_philosophers;
sem_t					*g_queue_semaphore;
sem_t					*g_forks_semaphore;
sem_t					*g_message_semaphore;
sem_t					*g_start_semaphore;

extern					pthread_mutex_t	g_messages_mutex;

enum	e_philo_errors {OK, DIED, M_LO_ER, M_UL_ER, \
	MAL_ER, S_I_ER, S_W_ER, S_P_ER, S_D_ER};

enum	e_mess_length {EAT_LEN = 11, SLEEP_LEN = 13, THINK_LEN = 13, \
	FORK_LEN = 18, DEAD_LEN = 6};

typedef struct			s_terms
{
	long long int		number_of_philosophers;
	long long int		time_to_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	long long int		number_of_times_each_philosopher_must_eat;
}						t_terms;

typedef struct			s_philo
{
	double				ts_ate_last_time;
	long long int		number;
	char				*number_char;
	int					number_len;
	long long int		time_to_die;
	long long int		time_to_eat;
	long long int		time_to_sleep;
	sem_t				*vitality;
	char				*sem_name;
	pthread_t			thread;
	pthread_t			life;
	long long int		max_meals;
	long long int		meals_counter;
}						t_philo;

int						ft_strlen(const char *s);
void					ft_putstr_fd(char *s, int fd);
int						ft_atol(const char *nptr, long long int *num_ptr);
char					*ft_llitoa(long long int n);
char					*ft_strjoin(char const *s1, char const *s2);

void					show_terms(t_terms *terms);
int						check_terms(int argc, char **argv, t_terms *terms);
double					get_ms_timestamp(void);

t_philo					*philo_return_null(int error);
void					start_simulation(t_terms *terms);

int						put_timestamp();
int						put_message(t_philo *philo, const char *mess,
															int count);
int						put_is_dead_message(t_philo *philo);
int						philo_try_to_eat(t_philo *philo);

sem_t					*init_semaphore(const char *name, int value);
sem_t					*lifes_sem_init(t_philo *philo);
void					unlink_semaphore(t_philo *table);
void					philo_join(t_philo *table);
void					*philo_lifetime(void *args);
void					*check_philo(void *args);
int						philo_check_meals_counter(t_philo *philo);
void					*philo_dead(t_philo *philo);
void					wait_processes(void);
void					kill_all_pids(int *pid_ids);
t_philo					*create_philo(t_terms *terms, long long int cur_num);
int						philo_process(t_terms *terms, long long int i);
#endif
