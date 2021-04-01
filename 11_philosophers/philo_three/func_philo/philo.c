/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:45:16 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/30 21:02:38 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void			philo_join(t_philo *table)
{
	long long int	i;

	i = 0;
	while (i < g_number_of_philosophers)
	{
		if (pthread_join(table[i].life, NULL) != 0)
		{
			printf("%s", PTHREAD_JOIN_ERR);
			return ;
		}
		if (pthread_join(table[i].thread, NULL) != 0)
		{
			printf("%s", PTHREAD_JOIN_ERR);
			return ;
		}
		i += 1;
	}
	return ;
}

int				philo_sleep(t_philo *philo)
{
	int	z;

	z = 0;
	if (!g_all_alive)
		return (0);
	if (!g_all_alive || (z = put_message(philo, PHILO_SLEEP, SLEEP_LEN)) > 0)
		return (z);
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

int				philo_think(t_philo *philo)
{
	int	z;

	z = 0;
	if (!g_all_alive)
		return (0);
	if (!g_all_alive ||
	(z = put_message(philo, PHILO_THINKING, THINK_LEN)) > 0)
		return (z);
	return (0);
}

void			*philo_lifetime(void *args)
{
	int		z;
	t_philo	*philo;

	philo = (t_philo*)args;
	if (philo->max_meals == 0)
		return (NULL);
	while (philo->meals_counter != philo->max_meals && g_all_alive)
	{
		if ((z = philo_try_to_eat(philo)) > 0)
			return (philo_return_null(z));
		if ((z = philo_sleep(philo)) > 0)
			return (philo_return_null(z));
		if ((z = philo_think(philo)) > 0)
			return (philo_return_null(z));
	}
	return (NULL);
}

void			*check_philo(void *args)
{
	t_philo		*philos;

	philos = (t_philo*)args;
	while (g_all_alive)
	{
		sem_wait(philos->vitality);
		if (get_ms_timestamp() - philos->ts_ate_last_time >
		(double)philos->time_to_die && g_all_alive)
		{
			philo_dead(philos);
			exit(20);
		}
		sem_post(philos->vitality);
		usleep(1000);
	}
	return (NULL);
}
