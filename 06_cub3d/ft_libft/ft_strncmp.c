/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:15:05 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/10 18:39:40 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char*)s1;
	u_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (u_s1[i] == u_s2[i])
		{
			if (u_s1[i] == '\0')
				return (0);
			i += 1;
		}
		else
			return (u_s1[i] - u_s2[i]);
	}
	return (0);
}
