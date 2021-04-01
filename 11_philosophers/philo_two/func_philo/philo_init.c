/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:35:16 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/28 03:22:59 by qmalcom          ###   ########.fr       */
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
