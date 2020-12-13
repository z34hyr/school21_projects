/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:10:09 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/09 04:25:32 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	c_c;

	c_c = (char)c;
	if (*s == c_c)
		return ((char*)s);
	while (*s != '\0' && s != NULL)
	{
		if (*s == c_c)
			return ((char*)s);
		s += 1;
	}
	if (*s == '\0' && c_c == '\0')
		return ((char*)s);
	return (NULL);
}
