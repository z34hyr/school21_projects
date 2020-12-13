/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:49:39 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 15:59:00 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest_c;
	const char	*src_c;
	char		c_c;

	c_c = (char)c;
	i = 0;
	dest_c = (char*)dest;
	src_c = (char*)src;
	while (i < n)
	{
		*dest_c = *src_c;
		if (*dest_c == c_c)
			return (dest_c + 1);
		dest_c += 1;
		src_c += 1;
		i += 1;
	}
	return (NULL);
}
