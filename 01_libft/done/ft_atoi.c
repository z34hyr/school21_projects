/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 07:05:44 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/07 23:01:49 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

static int				ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int				ft_todigit(char c)
{
	if (ft_isdigit(c))
		return ((int)c - 48);
	return (-1);
}

static long long int	ft_isnotll(int sign, int curr_dig, long long int numb)
{
	long long int num_max;
	long long int num_min;

	num_max = 9223372036854775807;
	num_min = num_max * (-1);
	if (sign == 1 && ((numb == num_max / 10 && curr_dig > 7) \
	|| numb > num_max / 10))
		return (-1);
	if (sign == -1 && ((numb * sign == num_min / 10 && curr_dig > 7) \
	|| numb * sign < num_min / 10))
		return (0);
	numb = numb * 10 + curr_dig;
	return (numb);
}

int						ft_atoi(const char *nptr)
{
	int				sign;
	int				curr_digit;
	long long int	num;

	sign = 1;
	num = 0;
	curr_digit = 0;
	while (ft_isspace(*nptr))
		nptr += 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr += 1;
	}
	while (*nptr == '0')
		nptr += 1;
	while (nptr != NULL && (curr_digit = ft_todigit(*(nptr++))) >= 0)
	{
		num = ft_isnotll(sign, curr_digit, num);
		if (num == 0 || num == -1)
			return (num);
	}
	return ((int)num * sign);
}
