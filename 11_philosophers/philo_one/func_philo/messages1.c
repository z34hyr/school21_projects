/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 14:29:24 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/30 23:09:16 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void		*philo_dead(t_philo *philo)
{
	pthread_mutex_lock(&g_messages_mutex);
	if (g_all_alive)
	{
		if (put_timestamp() == -1)
			return (philo_return_null(MALLOC_ER));
		write(1, philo->number_char, philo->number_len);
		write(1, PHILO_DEAD, DEAD_LEN);
	}
	g_all_alive = 0;
	pthread_mutex_unlock(&g_messages_mutex);
	pthread_mutex_unlock(philo->vitality);
	return (philo_return_null(DIED));
}

int			put_message(t_philo *philo, const char *mess, int count)
{
	pthread_mutex_lock(&g_messages_mutex);
	if (g_all_alive)
	{
		if (put_timestamp() == -1)
			return (MALLOC_ER);
		write(1, philo->number_char, philo->number_len);
		write(1, mess, count);
	}
	pthread_mutex_unlock(&g_messages_mutex);
	return (0);
}
