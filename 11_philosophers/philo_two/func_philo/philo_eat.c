/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 03:57:35 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/28 16:13:05 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** errors:
** 1 - philo is just dead
** 2 - pthread_mutex_lock error
** 3 - pthread_mutex_unlock error
** 4 - malloc error
*/

#include "../philo.h"

static int		philo_wait_two_forks(t_philo *philo)
{
	int	z;

	z = 0;
	if (!g_all_alive)
		return (0);
	if (sem_wait(g_queue_semaphore))
		return (S_W_ER);
	if (sem_wait(g_forks_semaphore))
		return (S_W_ER);
	if (!g_all_alive)
		return (sem_post(g_queue_semaphore));
	if (g_all_alive && (z = put_message(philo, PHILO_TAKE_FORK, FORK_LEN) > 0))
		return (z);
	if (sem_wait(g_forks_semaphore))
		return (S_W_ER);
	if (!g_all_alive)
		return (sem_post(g_queue_semaphore));
	if (sem_post(g_queue_semaphore))
		return (S_P_ER);
	if (g_all_alive && (z = put_message(philo, PHILO_TAKE_FORK, FORK_LEN) > 0))
		return (z);
	return (0);
}

static int		philo_local_check_is_alive(t_philo *philo)
{
	if (sem_wait(philo->vitality))
		return (S_W_ER);
	if (get_ms_timestamp() - philo->ts_ate_last_time >
	(double)philo->time_to_die)
	{
		sem_post(philo->vitality);
		return (DIED);
	}
	if (sem_post(philo->vitality))
		return (S_P_ER);
	if (!g_all_alive)
		return (DIED);
	return (0);
}

static int		philo_eat(t_philo *philo)
{
	int	z;

	if ((z = put_message(philo, PHILO_EAT, EAT_LEN)) > 0)
		return (z);
	if (sem_wait(philo->vitality))
		return (S_W_ER);
	if (philo_check_meals_counter(philo) > 0 || !g_all_alive)
		return (OK);
	philo->ts_ate_last_time = get_ms_timestamp();
	philo->meals_counter += 1;
	if (sem_post(philo->vitality))
		return (S_P_ER);
	usleep(philo->time_to_eat * 1000);
	return (0);
}

static int		philo_release_forks(void)
{
	if (sem_post(g_forks_semaphore))
		return (S_P_ER);
	if (sem_post(g_forks_semaphore))
		return (S_P_ER);
	return (0);
}

int				philo_try_to_eat(t_philo *philo)
{
	int	z;

	if (!g_all_alive)
		return (0);
	if ((z = philo_wait_two_forks(philo)) > 0)
		return (z);
	if ((z = philo_local_check_is_alive(philo)) > 0)
		return (z);
	if ((z = philo_eat(philo)) > 0)
		return (z);
	if ((z = philo_release_forks()) > 0)
		return (z);
	return (0);
}
