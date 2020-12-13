/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:57:08 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/23 01:05:51 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_handler(const char *string, int *i, int *counter, va_list a)
{
	char	*str;
	int		struct_res;
	int		q;
	t_conv	*conv;

	struct_res = 0;
	*i += 1;
	q = 0;
	if ((q = get_conv_line(&str, string, i)) == 1)
	{
		if ((struct_res = fill_conv_struct(str, &conv, a)) == -1)
			return (-1);
		else if (struct_res == 0)
		{
			*counter += write(1, "%", 1);
			*counter += write(1, str, ft_strlen(str));
		}
		else
			to_flag_func(conv, a, counter);
		free_before_exit(str);
	}
	if (q == -1 || *counter == -1)
		return (-1);
	return (0);
}
