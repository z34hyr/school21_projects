/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:35:16 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/30 19:20:38 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

sem_t	*init_semaphore(const char *name, int value)
{
	sem_t	*sema;
	int		i;

	sema = NULL;
	if ((sema = sem_open(name, O_CREAT | O_EXCL, 0644, value)) == SEM_FAILED
	&& errno == EEXIST)
	{
		sem_unlink(name);
		sema = sem_open(name, O_CREAT | O_EXCL, 0644, value);
	}
	sem_getvalue(sema, &i);
	return (sema);
}

void	unlink_semaphore(t_philo *table)
{
	if (table->sem_name)
	{
		if (sem_close(table->vitality) == EINVAL)
			printf("can't close %s\n", table->sem_name);
		if (sem_unlink(table->sem_name) == ENOENT)
			printf("no sema with name %s\n", table->sem_name);
	}
}

int		fill_arrays(int number, t_philo *philo)
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

t_philo	*create_philo(t_terms *terms, long long int cur_num)
{
	t_philo	*philo;

	if (!(philo = malloc(sizeof(t_philo))))
	{
		printf("%s", MAL_ERROR);
		exit(0);
	}
	philo->number = cur_num + 1;
	philo->max_meals = terms->number_of_times_each_philosopher_must_eat;
	philo->meals_counter = 0;
	philo->time_to_die = terms->time_to_die;
	philo->time_to_eat = terms->time_to_eat;
	philo->time_to_sleep = terms->time_to_sleep;
	if (fill_arrays(cur_num + 1, philo))
		return (philo_return_null(MAL_ER));
	philo->vitality = init_semaphore(philo->sem_name, 1);
	philo->number_len = ft_strlen(philo->number_char);
	return (philo);
}
