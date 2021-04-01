/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 03:57:35 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/30 23:39:56 by qmalcom          ###   ########.fr       */
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
		return (1);
	if (pthread_mutex_lock(&philo->forks[philo->left_fork]))
		return (MU_LO_ER);
	if (g_all_alive && (z = put_message(philo, PHILO_TAKE_FORK, FORK_LEN) > 0))
		return (z);
	if (!g_all_alive)
		return (1);
	if (pthread_mutex_lock(&philo->forks[philo->right_fork]))
		return (MU_UNLO_ER);
	if (g_all_alive && (z = put_message(philo, PHILO_TAKE_FORK, FORK_LEN) > 0))
		return (z);
	return (0);
}

static int		philo_eat(t_philo *philo)
{
	int	z;

	if (pthread_mutex_lock(philo->vitality))
		return (MU_LO_ER);
	if ((z = put_message(philo, PHILO_EAT, EAT_LEN)) > 0)
		return (z);
	if (philo_check_meals_counter(philo) > 0 || !g_all_alive)
		return (OK);
	philo->ts_ate_last_time = get_ms_timestamp();
	philo->meals_counter += 1;
	if (pthread_mutex_unlock(philo->vitality))
		return (MU_UNLO_ER);
	usleep(philo->time_to_eat * 1000);
	return (0);
}

static int		philo_release_forks(t_philo *philo)
{
	if (pthread_mutex_unlock(&philo->forks[philo->right_fork]) > 0)
		return (MU_UNLO_ER);
	if (pthread_mutex_unlock(&philo->forks[philo->left_fork]) > 0)
		return (MU_UNLO_ER);
	return (0);
}

int				philo_try_to_eat(t_philo *philo)
{
	int	z;

	if (!g_all_alive)
		return (0);
	if ((z = philo_wait_two_forks(philo)) > 0)
		return (z);
	if ((z = philo_eat(philo)) > 0)
		return (z);
	if ((z = philo_release_forks(philo)) > 0)
		return (z);
	return (0);
}
