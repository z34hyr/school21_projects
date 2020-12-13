/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_struc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:39:09 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/24 01:03:53 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** cf_ - conversion flag
** c_ - conversion
** cs - conversion specifier
*/

t_conv	*ft_conv_new(char *conv_line)
{
	t_conv *new_conv;

	if (!(new_conv = malloc(sizeof(t_conv))))
		return (NULL);
	new_conv->cf_space = 0;
	new_conv->cf_plus = 0;
	new_conv->cf_minus = 0;
	new_conv->cf_sharp = 0;
	new_conv->cf_zero = 0;
	new_conv->cf_dot = 0;
	new_conv->c_width = 0;
	new_conv->flag_ast = 0;
	new_conv->c_precision = 0;
	new_conv->prec_width = 0;
	new_conv->cs = conv_line[ft_strlen(conv_line) - 1];
	return (new_conv);
}

void	conv_flags_sifter(t_conv *conv_struct, char *conv_line, int *i)
{
	while (conv_line[*i] == ' ' || conv_line[*i] == '+' ||
		conv_line[*i] == '-' || conv_line[*i] == '0' || conv_line[*i] == '#')
	{
		if (conv_line[*i] == ' ')
			conv_struct->cf_space = 1;
		if (conv_line[*i] == '+')
			conv_struct->cf_plus = 1;
		if (conv_line[*i] == '-')
			conv_struct->cf_minus = 1;
		if (conv_line[*i] == '0')
			conv_struct->cf_zero = 1;
		if (conv_line[*i] == '#')
			conv_struct->cf_sharp = 1;
		*i += 1;
	}
	if (conv_struct->cf_space == 1 && conv_struct->cf_plus == 1)
		conv_struct->cf_space = 0;
	if (conv_struct->cf_zero == 1 && conv_struct->cf_minus == 1)
		conv_struct->cf_zero = 0;
	if (conv_struct->cf_space == 1 && conv_struct->cf_plus == 1)
		conv_struct->cf_space = 0;
}

/*
** here we handle width.
** if * is less than zero, so set - flag to 1 and zero flag to 0
*/

void	get_width(t_conv *conv_struct, char *conv_line, int *i, va_list a)
{
	int j;

	j = 0;
	if (is_digit(conv_line[*i]))
		conv_struct->c_width = ft_atoi(conv_line, i);
	else if (conv_line[*i] == '*')
	{
		j = va_arg(a, int);
		if (j < 0)
		{
			j *= -1;
			conv_struct->cf_minus = 1;
			conv_struct->cf_zero = 0;
		}
		conv_struct->c_width = j;
		*i += 1;
	}
}

void	get_precision(t_conv *conv_struct, char *conv_line, int *i, va_list a)
{
	if (conv_line[*i] == '.')
	{
		*i += 1;
		conv_struct->cf_dot = 1;
		if (is_digit(conv_line[*i]))
			conv_struct->prec_width = ft_atoi(conv_line, i);
		else if (conv_line[*i] == '*')
		{
			conv_struct->prec_width = va_arg(a, int);
			*i += 1;
		}
	}
}

/*
** if malloc error - can't do ft_printf, so free conv_line and return -1
** if some flag error, return 0 and not free conv_line
** else return 1 - successfully create conv_struct
*/

int		fill_conv_struct(char *conv_line, t_conv **conv_struc, va_list a)
{
	int i;

	i = 0;
	if (!(*conv_struc = ft_conv_new(conv_line)))
	{
		free(conv_line);
		conv_line = NULL;
		return (-1);
	}
	conv_flags_sifter(*conv_struc, conv_line, &i);
	get_width(*conv_struc, conv_line, &i, a);
	get_precision(*conv_struc, conv_line, &i, a);
	if ((*conv_struc)->cf_zero == 1 && (*conv_struc)->cf_dot == 1)
		(*conv_struc)->cf_zero = 0;
	if (is_conv_flag(conv_line[i]) || is_digit(conv_line[i]))
	{
		free(*conv_struc);
		*conv_struc = NULL;
		return (0);
	}
	(*conv_struc)->cs = conv_line[i];
	return (1);
}
