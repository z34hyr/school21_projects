/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:27:35 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/23 23:45:24 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_len(int n)
{
	int len;

	len = 0;
	while ((n /= 10))
		len += 1;
	return (len + 1);
}

static void	fill_arr(char *arr, int n, int len)
{
	while (n / 10)
	{
		arr[len--] = n % 10 + 48;
		n = n / 10;
	}
	arr[len] = n + 48;
	if (len)
		arr[--len] = '-';
}

char		*ft_itoa(int n)
{
	int		n_len;
	char	*arr_n;
	int		extr_val;

	extr_val = 0;
	n_len = 0;
	if (n == -2147483648)
	{
		extr_val = 1;
		n /= 10;
	}
	if (n < 0)
	{
		n_len += 1;
		n = n * (-1);
	}
	n_len += num_len(n) + extr_val;
	if (!(arr_n = (char*)malloc(n_len + 1)))
		return (NULL);
	arr_n[n_len--] = '\0';
	if (extr_val)
		arr_n[n_len--] = '8';
	fill_arr(arr_n, n, n_len);
	return (arr_n);
}
