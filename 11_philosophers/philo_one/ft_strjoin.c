/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:18:34 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/23 00:08:55 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*str_sum;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str_sum = (char*)malloc(s1_len + s2_len + 1)))
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str_sum[i] = s1[i];
		i += 1;
	}
	while (i < s1_len + s2_len)
	{
		str_sum[i] = s2[i - s1_len];
		i += 1;
	}
	str_sum[i] = '\0';
	return (str_sum);
}
