/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:36:24 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 23:21:21 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res_s;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL || !(res_s = ft_calloc(ft_strlen(s) + 1, 1)))
		return (NULL);
	while (s[i])
	{
		res_s[i] = f(i, s[i]);
		i += 1;
	}
	res_s[i] = '\0';
	return (res_s);
}
