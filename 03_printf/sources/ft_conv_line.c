/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:34:27 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/23 23:44:33 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_digit(char symb)
{
	if (symb >= 48 && symb <= 57)
		return (1);
	return (0);
}

int		is_conv_flag(char symb)
{
	if (symb == ' ' || symb == '.' || symb == '*' ||
	symb == '#' || symb == '-' || symb == '+')
		return (1);
	return (0);
}

int		is_conv_spec(char symb)
{
	if (symb == 'd' || symb == 'i' || symb == 'u' || symb == 'x' ||
	symb == 'X' || symb == 's' || symb == 'p' || symb == 'c' ||
	symb == '%' || symb == 'n')
		return (1);
	return (0);
}

char	*fill_conv_line(char *dst, const char *src, int start, int length)
{
	int i;

	i = 0;
	while (i < length)
	{
		dst[i] = src[start + i];
		i += 1;
	}
	dst[i] = '\0';
	return (dst);
}

/*
** returns	|0 - no conversion specifier after %, write line_len + 1 symbols
** 			|-1 - malloc error
** 			|1 - in dst we have format description
** (conversion flags)(conversion specifier)
*/

int		get_conv_line(char **dst, const char *string, int *i)
{
	int line_len;

	line_len = 0;
	while (string[*i] && (is_conv_flag(string[*i]) || is_digit(string[*i])))
	{
		line_len += 1;
		*i += 1;
	}
	if (string[*i] && is_conv_spec(string[*i]))
	{
		line_len += 1;
		*i += 1;
	}
	else
	{
		write(1, &string[*i] - line_len - 1, line_len + 1);
		return (0);
	}
	if (!line_len || !(*dst = (char*)malloc(line_len + 1)))
		return (-1);
	*dst = fill_conv_line(*dst, string, *i - line_len, line_len);
	return (1);
}
