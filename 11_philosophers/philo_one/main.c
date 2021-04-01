/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 00:16:04 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/25 17:44:21 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

double				get_ms_timestamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((double)current_time.tv_sec * 1000.0 +
			(double)current_time.tv_usec / 1000.0);
}

int					put_timestamp(void)
{
	char	*timestamp_arr;

	if (!(timestamp_arr =
	ft_llitoa((long long int)(get_ms_timestamp() - g_ts_simulation_start))))
		return (1);
	ft_putstr_fd(timestamp_arr, 1);
	free(timestamp_arr);
	return (0);
}

int					main(int argc, char **argv)
{
	t_terms				terms;
	t_philo				*table;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*lifes;

	table = NULL;
	forks = NULL;
	lifes = NULL;
	if (!check_terms(argc, argv, &terms) &&
	(forks = init_mutex(&terms)) &&
	(lifes = init_mutex(&terms)) &&
	(table = fill_table(&terms, forks, lifes)))
	{
		start_simulation(table, &terms);
		philo_join(table);
	}
	if (forks)
		free(forks);
	if (lifes)
		free(lifes);
	free_table(table);
	return (0);
}
