/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:29:24 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/28 16:06:02 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int			put_message(t_philo *philo, const char *mess, int count)
{
	if (sem_wait(g_message_semaphore) == -1)
		return (S_W_ER);
	if (g_all_alive)
	{
		if (put_timestamp() == -1)
			return (4);
		write(1, philo->number_char, philo->number_len);
		write(1, mess, count);
	}
	if (sem_post(g_message_semaphore) == -1)
		return (S_P_ER);
	return (0);
}

t_philo		*philo_return_null(int error)
{
	char	*err_string;

	if (error == 4)
		err_string = MAL_ERROR;
	else if (error == 2)
		err_string = MUTEX_LOCK_ERR;
	else if (error == 3)
		err_string = MUTEX_UNLOCK_ERR;
	else if (error == 5)
		err_string = SEM_INIT_ERR;
	else if (error == 6)
		err_string = SEM_WAIT_ERR;
	else if (error == 7)
		err_string = SEM_POST_ERR;
	else if (error == 8)
		err_string = SEM_DESTR_ERR;
	else if (error == 1 || error == 0)
		return (NULL);
	printf("%s", err_string);
	return (NULL);
}

int			philo_check_meals_counter(t_philo *philo)
{
	if (philo->max_meals >= 0 &&
		philo->meals_counter == philo->max_meals)
	{
		if (sem_post(philo->vitality) > 0)
		{
			philo_return_null(S_P_ER);
			return (1);
		}
		return (1);
	}
	return (0);
}

void		*philo_dead(t_philo *philo)
{
	sem_wait(g_message_semaphore);
	if (g_all_alive)
	{
		put_timestamp();
		write(1, philo->number_char, philo->number_len);
		write(1, PHILO_DEAD, DEAD_LEN);
	}
	g_all_alive = 0;
	sem_post(g_message_semaphore);
	sem_post(philo->vitality);
	return (philo_return_null(DIED));
}
