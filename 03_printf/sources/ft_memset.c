/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:52:59 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/22 19:53:16 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
