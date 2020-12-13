/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:16:01 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/09 04:32:52 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	size_t	len;

	len = ft_strlen(s);
	if (!(s_copy = (char*)malloc(len + 1)))
		return (NULL);
	while (*s != '\0')
		*s_copy++ = *s++;
	*s_copy = '\0';
	return (s_copy - len);
}
