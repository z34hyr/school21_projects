/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 02:40:13 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/25 05:16:12 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int				error_terms(char *err_string)
{
	printf("%s", err_string);
	printf("%s", USAGE1);
	printf("%s", USAGE2);
	printf("%s", USAGE3);
	printf("%s", USAGE4);
	printf("%s", USAGE5);
	printf("%s", USAGE6);
	return (1);
}

int				check_terms(int argc, char **argv, t_terms *terms)
{
	if (argc != 5 && argc != 6)
		return (error_terms(WRONG_NUM_ARGS));
	if ((ft_atol(argv[1], &terms->number_of_philosophers) == -1 || \
	terms->number_of_philosophers <= 0) || \
	(ft_atol(argv[2], &terms->time_to_die) == -1 || terms->time_to_die < 1) ||\
	(ft_atol(argv[3], &terms->time_to_eat) == -1 || terms->time_to_eat < 1) ||\
	(ft_atol(argv[4], &terms->time_to_sleep) == -1 || \
	terms->time_to_sleep <= 0) || \
	(argc == 6 && (ft_atol(argv[5], \
	&terms->number_of_times_each_philosopher_must_eat) == -1 || \
	terms->number_of_times_each_philosopher_must_eat < 0)) || \
	terms->time_to_die <= terms->time_to_eat)
		return (error_terms(WRONG_ARG));
	g_number_of_philosophers_global = terms->number_of_philosophers;
	if (argc == 5)
		terms->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}

void			show_terms(t_terms *terms)
{
	printf("number_of_philosophers: %lld;\n \
	time_to_die: %lld;\n \
	time_to_eat: %lld;\n \
	time_to_sleep: %lld;\n \
	number_of_times_each_philosopher_must_eat: %lld\n", \
	terms->number_of_philosophers, \
	terms->time_to_die, \
	terms->time_to_eat, \
	terms->time_to_sleep, \
	terms->number_of_times_each_philosopher_must_eat);
}
