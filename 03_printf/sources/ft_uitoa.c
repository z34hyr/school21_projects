/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:27:35 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/23 23:47:13 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(unsigned int n)
{
	int len;

	len = 0;
	while ((n /= 10))
		len += 1;
	return (len + 1);
}

static void	fill_arr(char *arr, unsigned int n, int len)
{
	while (n / 10)
	{
		arr[len--] = n % 10 + 48;
		n = n / 10;
	}
	arr[len] = n + 48;
}

char		*ft_uitoa(unsigned int n)
{
	int		n_len;
	char	*arr_n;

	n_len = 0;
	n_len += num_len(n);
	if (!(arr_n = (char*)malloc(n_len + 1)))
		return (NULL);
	arr_n[n_len--] = '\0';
	fill_arr(arr_n, n, n_len);
	return (arr_n);
}
