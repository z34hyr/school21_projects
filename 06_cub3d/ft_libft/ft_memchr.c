/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:02:15 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 16:02:27 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc_c;
	unsigned char	*uc_s;
	size_t			i;

	uc_c = (unsigned char)c;
	uc_s = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (uc_s[i] == uc_c)
			return (&uc_s[i]);
		i += 1;
	}
	return (NULL);
}
