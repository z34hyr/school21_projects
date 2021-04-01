/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 07:05:44 by qmalcom           #+#    #+#             */
/*   Updated: 2021/03/25 20:37:22 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int				ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int				ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
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

/*
** nptr - pointer to string where number lies
** num_ptr - where to write a number
*/

int						ft_atol(const char *nptr, long long int *num_ptr)
{
	int				sign;
	int				curr_digit;

	*num_ptr = 0;
	curr_digit = 0;
	while (ft_isspace(*nptr))
		nptr += 1;
	sign = (*nptr == '-' ? -1 : 1);
	nptr += (*nptr == '-' || *nptr == '+' ? 1 : 0);
	while (*nptr == '0')
		nptr += 1;
	while (nptr != NULL && *nptr != '\0' &&
	(curr_digit = ft_todigit(*(nptr++))) >= 0)
	{
		if ((*num_ptr = ft_isnotll(sign, curr_digit, *num_ptr)) == 0 ||
		*num_ptr == -1)
			return (0);
	}
	if (curr_digit == -1)
		return (-1);
	*num_ptr *= sign;
	return (0);
}
