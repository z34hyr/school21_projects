/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 22:27:07 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/23 01:02:43 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strlen(char *string)
{
	int i;

	i = 0;
	if (!string)
		return (0);
	while (string[i])
		i++;
	return (i);
}

/*
** regular write.
** Write 'length' symbol(s) before EOL\'%' symbol
*/

int			reg_write(const char *string, int start, int *length)
{
	int counter;

	counter = 0;
	if (*length > 0 && (!string[start] || string[start] == '%'))
	{
		counter = *length;
		write(1, &string[start - *length], *length);
		*length = 0;
	}
	return (counter);
}

/*
** First of all we are looking for %
** If we see no %, just rising counter of regular symbols
** if we see % - write previous symbols by counter,
** then analyzing what is next with function get_conv_line
** if OK, then creating and filling structure
** if it conv flags - going further
** if not - just writing % and all after it
** if last symbol is not conv specifier - just writing
** else - malloc line, all after %, conv spec - last symbol
** then sifting this line, creting new struct element,
** after that - calling needed conv spec function
*/

int			parser(const char *string, va_list a)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	j = 0;
	counter = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (ft_conv_handler(string, &i, &counter, a) == -1)
				return (-1);
		}
		else
		{
			j += 1;
			i += 1;
		}
		counter += reg_write(string, i, &j);
	}
	return (counter);
}

int			ft_printf(const char *string, ...)
{
	int				f;
	va_list			ap;

	f = 0;
	va_start(ap, string);
	f = parser(string, ap);
	va_end(ap);
	return (f);
}
