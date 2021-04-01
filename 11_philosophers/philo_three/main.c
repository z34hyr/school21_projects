/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:16:04 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/30 19:00:12 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** philo one - philosopher with threads and mutex
**
** program gets 4 arguments, and fifth is optional
** 1. number_of_philosophers
** 2. time_to_die - milliseconds
** 3. time_to_eat - milliseconds
** 4. time_to_sleep - milliseconds
** optional 5. number_of_times_each_philosopher_must_eat
*/

double	get_ms_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((double)current_time.tv_sec * 1000.0 +
			(double)current_time.tv_usec / 1000.0);
}

int		put_timestamp(void)
{
	char	*timestamp_arr;

	if (!(timestamp_arr =
	ft_llitoa((long long int)(get_ms_timestamp() - g_ts_simulation_start))))
		return (1);
	ft_putstr_fd(timestamp_arr, 1);
	free(timestamp_arr);
	return (0);
}

void	unlink_semaphores(void)
{
	if (sem_unlink("/queue") == -1)
		printf("sem_unlink error\n");
	if (sem_close(g_queue_semaphore) == -1)
		printf("queue sem_close error\n");
	if (sem_unlink("/forks") == -1)
		printf("sem_unlink error\n");
	if (sem_close(g_forks_semaphore) == -1)
		printf("forks sem_close error\n");
	if (sem_unlink("/message") == -1)
		printf("sem_unlink error\n");
	if (sem_close(g_message_semaphore) == -1)
		printf("message sem_close error\n");
}

int		main(int argc, char **argv)
{
	t_terms				terms;

	if (!check_terms(argc, argv, &terms))
		start_simulation(&terms);
	unlink_semaphores();
	return (0);
}
