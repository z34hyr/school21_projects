/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:29:24 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/28 17:46:13 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int			put_full_message(t_philo *philo)
{
	if (pthread_mutex_lock(&g_messages_mutex))
		return (2);
	if (put_timestamp() == -1)
		return (4);
	write(1, philo->number_char, philo->number_len);
	write(1, " has eaten enough - ", 20);
	printf("%lld times\n", philo->meals_counter);
	if (pthread_mutex_unlock(&g_messages_mutex) > 0)
		return (3);
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
		if (pthread_mutex_unlock(philo->vitality) > 0)
		{
			philo_return_null(3);
			return (1);
		}
		return (1);
	}
	return (0);
}
