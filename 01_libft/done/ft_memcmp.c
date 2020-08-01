/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:03:10 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 17:04:21 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;
	size_t			i;

	uc_s1 = (unsigned char*)s1;
	uc_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (uc_s1[i] == uc_s2[i])
		{
			if (i == n - 1)
				return (0);
			i += 1;
		}
		else
			return ((int)uc_s1[i] - uc_s2[i]);
	}
	return (0);
}
