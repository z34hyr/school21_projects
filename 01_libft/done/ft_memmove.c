/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:00:16 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 16:00:29 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_c;
	const char	*src_c;

	i = 0;
	dest_c = (char*)dest;
	src_c = (char*)src;
	if (dest >= src)
		while (n-- > 0)
			dest_c[n] = src_c[n];
	else if (dest < src)
	{
		while (i < n)
		{
			dest_c[i] = src_c[i];
			i += 1;
		}
	}
	return (dest);
}
