/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:10:39 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/09 01:18:32 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c_c;
	size_t	i;

	i = ft_strlen(s);
	c_c = (char)c;
	while (i != 0)
	{
		if (s[i] == c_c)
			return ((char*)&s[i]);
		i -= 1;
	}
	if (s[i] == c_c)
		return ((char*)s);
	return (NULL);
}
