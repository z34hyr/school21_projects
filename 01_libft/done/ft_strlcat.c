/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:09:48 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/10 18:39:09 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_size;
	size_t src_size;
	size_t i;

	dst_size = 0;
	i = 0;
	while (dst_size < size && dst[dst_size] != '\0')
		dst_size += 1;
	src_size = ft_strlen(src);
	if (dst_size > size - 1)
		return (size + src_size);
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - dst_size - 1))
		{
			dst[dst_size + i] = src[i];
			i += 1;
		}
		dst[dst_size + i] = '\0';
	}
	return (dst_size + src_size);
}
