/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:17:46 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/13 23:51:32 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_len;
	unsigned int	subs_len;
	char			*subs;
	unsigned int	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		start = s_len;
	if (s_len - start < len)
		subs_len = s_len - start;
	else
		subs_len = len;
	if (!(subs = (char*)malloc(subs_len + 1)))
		return (NULL);
	i = 0;
	while (i < subs_len)
	{
		subs[i] = s[start + i];
		i += 1;
	}
	subs[i] = '\0';
	return (subs);
}
