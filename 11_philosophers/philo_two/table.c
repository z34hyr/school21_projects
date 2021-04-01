/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:42:17 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/28 16:01:21 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		free_table(t_philo *table)
{
	long long int	i;

	i = -1;
	if (table)
	{
		while (++i < g_number_of_philosophers)
		{
			unlink_semaphore(&table[i]);
			if (table[i].number_char)
				free(table[i].number_char);
			if (table[i].sem_name)
				free(table[i].sem_name);
		}
		free(table);
	}
}

t_philo		*init_table(void)
{
	t_philo		*table;
	int			i;

	i = -1;
	if (!(table = malloc(sizeof(t_philo) * g_number_of_philosophers)))
		return (philo_return_null(MAL_ER));
	while (++i < g_number_of_philosophers)
		table[i].number_char = NULL;
	return (table);
}

int			fill_arrays(int number, t_philo *philo)
{
	char	*name;

	if (!(name = ft_llitoa(number)))
	{
		printf("%s", MAL_ERROR);
		return (1);
	}
	if (!(philo->number_char = ft_strjoin(" ", name)))
	{
		printf("%s", MAL_ERROR);
		free(name);
		return (1);
	}
	if (!(philo->sem_name = ft_strjoin("/", philo->number_char)))
	{
		printf("%s", MAL_ERROR);
		free(name);
		return (1);
	}
	free(name);
	return (0);
}

t_philo		*fill_table(t_terms *terms)
{
	t_philo			*table;
	long long int	i;

	i = 0;
	if (!(table = init_table()))
		return (NULL);
	while (i < terms->number_of_philosophers)
	{
		table[i].number = i + 1;
		table[i].max_meals = terms->number_of_times_each_philosopher_must_eat;
		table[i].meals_counter = 0;
		table[i].time_to_die = terms->time_to_die;
		table[i].time_to_eat = terms->time_to_eat;
		table[i].time_to_sleep = terms->time_to_sleep;
		if (fill_arrays(i + 1, &table[i]))
			return (philo_return_null(MAL_ER));
		table[i].vitality = init_semaphore(table[i].sem_name, 1);
		table[i].number_len = ft_strlen(table[i].number_char);
		i += 1;
	}
	g_queue_semaphore = init_semaphore("/queue", 1);
	g_forks_semaphore = init_semaphore("/forks", g_number_of_philosophers);
	g_message_semaphore = init_semaphore("/message", 1);
	return (table);
}

void		start_simulation(t_philo *table, t_terms *terms)
{
	long long int	i;

	i = 0;
	g_ts_simulation_start = get_ms_timestamp();
	g_all_alive = 1;
	while (i < terms->number_of_philosophers)
	{
		table[i].ts_ate_last_time = g_ts_simulation_start;
		if (pthread_create(&table[i].thread, NULL,
		philo_lifetime, (void*)&table[i]))
			return ;
		if (pthread_create(&table[i].life, NULL,
		check_philo, (void*)&table[i]))
			return ;
		i += 1;
	}
}
