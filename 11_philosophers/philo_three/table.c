/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:42:17 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/30 21:13:29 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		*init_table(void)
{
	int	*pid_ids;

	if (!(pid_ids = (int*)malloc(sizeof(int) * g_number_of_philosophers)))
	{
		printf("%s", MAL_ERROR);
		exit(0);
	}
	memset(pid_ids, 0, g_number_of_philosophers);
	g_queue_semaphore = init_semaphore("/queue", 1);
	g_forks_semaphore = init_semaphore("/forks", g_number_of_philosophers);
	g_message_semaphore = init_semaphore("/message", 1);
	g_start_semaphore = init_semaphore("/startsem", 1);
	g_all_alive = 1;
	return (pid_ids);
}

void	start_simulation(t_terms *terms)
{
	long long int	i;
	int				num_pid;
	int				*pid_ids;

	i = -1;
	num_pid = 0;
	pid_ids = init_table();
	sem_wait(g_start_semaphore);
	while (++i < terms->number_of_philosophers)
	{
		num_pid = fork();
		if (!num_pid)
			break ;
		pid_ids[i] = num_pid;
	}
	if (!num_pid)
		philo_process(terms, i);
	sem_post(g_start_semaphore);
	wait_processes();
	kill_all_pids(pid_ids);
}

int		philo_process(t_terms *terms, long long int i)
{
	t_philo	*philo;

	if (!(philo = create_philo(terms, i)))
		return (1);
	sem_wait(g_start_semaphore);
	g_ts_simulation_start = get_ms_timestamp();
	sem_post(g_start_semaphore);
	philo->ts_ate_last_time = g_ts_simulation_start;
	if (pthread_create(&philo->thread, NULL,
	philo_lifetime, (void*)philo))
		return (1);
	if (pthread_create(&philo->life, NULL,
	check_philo, (void*)philo))
		return (1);
	pthread_join(philo->life, NULL);
	pthread_join(philo->thread, NULL);
	free(philo->number_char);
	free(philo->sem_name);
	free(philo);
	exit(0);
}

void	kill_all_pids(int *pid_ids)
{
	int	i;

	i = -1;
	while (++i < g_number_of_philosophers)
		kill(pid_ids[i], SIGKILL);
	free(pid_ids);
}

void	wait_processes(void)
{
	int status;
	int res;
	int n;

	n = g_number_of_philosophers;
	while (waitpid(-1, &status, WUNTRACED))
	{
		if (WIFEXITED(status))
		{
			if ((res = WIFEXITED(status)) == 20)
				break ;
			else if (res == 6)
			{
				n -= 1;
				if (n == 0)
					break ;
			}
			else
				break ;
		}
		else
			break ;
	}
}
