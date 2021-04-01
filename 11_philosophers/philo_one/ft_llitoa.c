/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 11:27:35 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/21 15:25:04 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	num_len(int n)
{
	int len;

	len = 0;
	while ((n /= 10))
		len += 1;
	return (len + 1);
}

static void	fill_arr(char *arr, long long int n, int len)
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

char		*ft_llitoa(long long int n)
{
	long long int		n_len;
	char				*arr_n;

	n_len = 0;
	if (n < 0)
	{
		n_len += 1;
		n = n * (-1);
	}
	n_len += num_len(n);
	if (!(arr_n = (char*)malloc(n_len + 1)))
		return (NULL);
	arr_n[n_len--] = '\0';
	fill_arr(arr_n, n, n_len);
	return (arr_n);
}
