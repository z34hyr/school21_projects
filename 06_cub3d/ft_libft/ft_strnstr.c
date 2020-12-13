/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:13:05 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/15 00:31:23 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t len_big;
	size_t len_little;
	size_t i;
	size_t j;

	if (!(len_little = ft_strlen(little)))
		return ((char*)big);
	len_big = ft_strlen(big);
	i = 0;
	j = 0;
	while (i < len && i < len_big)
	{
		while (j < len - i && big[i + j] && little[j] && \
		little[j] == big[i + j])
		{
			j += 1;
			if (!little[j])
				return ((char*)&big[i]);
			if (j == len)
				return (NULL);
		}
		i += 1;
		j = 0;
	}
	return (NULL);
}
