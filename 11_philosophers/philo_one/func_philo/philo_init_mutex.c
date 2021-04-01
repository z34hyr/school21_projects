/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:35:16 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/28 17:02:27 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t		*init_mutex(t_terms *terms)
{
	pthread_mutex_t		*mutex;
	long long int		i;

	i = 0;
	if (!(mutex = malloc(sizeof(pthread_mutex_t) *
	terms->number_of_philosophers)))
	{
		printf("%s", MAL_ERROR);
		return (NULL);
	}
	memset(mutex, 0, sizeof(pthread_mutex_t) * terms->number_of_philosophers);
	while (i < terms->number_of_philosophers)
	{
		if (pthread_mutex_init(&mutex[i], NULL))
		{
			printf("%s", MUTEX_INIT_ERR);
			return (NULL);
		}
		i += 1;
	}
	return (mutex);
}
