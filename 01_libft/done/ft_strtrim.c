/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:19:37 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 23:06:07 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_isinset(char const val, char const *set)
{
	while (*set != '\0')
		if (val == *set++)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	tr_str_len;
	char	*tr_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0' && ft_isinset(s1[i], set))
		i += 1;
	while (i + j < ft_strlen(s1) && ft_isinset(s1[ft_strlen(s1) - j - 1], set))
		j += 1;
	tr_str_len = ft_strlen(s1) - i - j;
	if (!(tr_str = (char*)malloc(tr_str_len + 1)))
		return (NULL);
	j = 0;
	while (j < tr_str_len)
	{
		tr_str[j] = s1[i + j];
		j += 1;
	}
	tr_str[j] = '\0';
	return (tr_str);
}
