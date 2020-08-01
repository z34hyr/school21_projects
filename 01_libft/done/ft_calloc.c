/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:04:00 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/13 23:53:23 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*c;
	size_t	m_size;

	m_size = nmemb * size;
	if (!(c = (char*)malloc(m_size)))
		return (NULL);
	ft_bzero(c, m_size);
	return (c);
}
