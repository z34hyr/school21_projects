/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:45:45 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 15:45:51 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	z;
	char	*q;

	i = 0;
	z = (char)c;
	q = (char*)s;
	while (i < n)
		q[i++] = z;
	s = (void*)q;
	return (s);
}
