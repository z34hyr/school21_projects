/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 07:05:44 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/22 22:50:05 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_todigit(char c)
{
	if (is_digit(c))
		return ((int)c - 48);
	return (-1);
}

int			ft_atoi(const char *nptr, int *i)
{
	int	curr_digit;
	int	num;

	num = 0;
	curr_digit = 0;
	while (nptr[*i] && (curr_digit = ft_todigit(nptr[*i])) >= 0)
	{
		num = num * 10 + curr_digit;
		*i += 1;
	}
	return (num);
}
