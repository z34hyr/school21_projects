/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:48:28 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/08 21:28:00 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_c;
	const char	*src_c;

	i = 0;
	dest_c = (char*)dest;
	src_c = (char*)src;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i += 1;
	}
	return (dest);
}
