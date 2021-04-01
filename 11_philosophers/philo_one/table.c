/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:42:17 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/28 17:42:56 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		free_table(t_philo *table)
{
	long long int	i;

	i = -1;
	if (table)
	{
		while (++i < g_number_of_philosophers_global)
		{
			if (table[i].number_char)
				free(table[i].number_char);
		}
		free(table);
	}
}

t_philo		*init_table(void)
{
	t_philo		*table;
	int			i;

	i = -1;
	if (!(table = malloc(sizeof(t_philo) * g_number_of_philosophers_global)))
		return (philo_return_null(MALLOC_ER));
	while (++i < g_number_of_philosophers_global)
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
	free(name);
	return (0);
}

t_philo		*fill_table(t_terms *terms,
pthread_mutex_t *forks, pthread_mutex_t *lifes)
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
		table[i].forks = forks;
		table[i].vitality = &lifes[i];
		table[i].left_fork = i;
		table[i].right_fork = (i + 1) % terms->number_of_philosophers;
		if (fill_arrays(i + 1, &table[i]))
			return (philo_return_null(MALLOC_ER));
		table[i].number_len = ft_strlen(table[i].number_char);
		i += 1;
	}
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
		usleep(1000);
		i += 1;
	}
}
