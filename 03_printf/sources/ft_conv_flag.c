/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 16:03:14 by qmalcom           #+#    #+#             */
/*   Updated: 2020/08/01 20:14:34 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	filler_line(char **dst, int len, char c)
{
	if (len > 0)
	{
		if (!(*dst = (char*)malloc(len + 1)))
			return (-1);
		*dst = ft_memset(*dst, c, len);
		*(*dst + len) = '\0';
		return (len);
	}
	return (0);
}

int	prec_line_i_d_u(char *str, char **prec_str, t_conv *conv_struc)
{
	int n_prec;

	n_prec = 0;
	if (conv_struc->cf_dot &&
	(n_prec = conv_struc->prec_width - ft_strlen(str)) >= 0)
	{
		if (str[0] == '-')
			n_prec += 1;
		return (filler_line(prec_str, n_prec, '0'));
	}
	else if (!conv_struc->cf_dot && conv_struc->cf_zero && \
	(n_prec = conv_struc->c_width - ft_strlen(str)) > 0)
		return (filler_line(prec_str, n_prec, '0'));
	return (0);
}

int	prec_line_s(char *str, t_conv *conv_struc)
{
	int n_prec;
	int str_len;

	n_prec = 0;
	str_len = ft_strlen(str);
	if (conv_struc->cf_dot && (conv_struc->prec_width > str_len ||
	conv_struc->prec_width == 0) &&
	(n_prec = conv_struc->prec_width - str_len) >= 0)
		n_prec = str_len;
	else if (conv_struc->cf_dot && conv_struc->prec_width == 0)
		n_prec = 0;
	else if (!conv_struc->cf_dot ||
	(conv_struc->cf_dot && conv_struc->prec_width < 0))
		n_prec = str_len;
	else if (conv_struc->prec_width > 0)
		n_prec = conv_struc->prec_width;
	return (n_prec);
}

int	space_line(char *str, char **space_str, t_conv *conv_struc, int n_prec)
{
	int		n_space;
	char	conv_spec;

	conv_spec = conv_struc->cs;
	n_space = 0;
	if (conv_spec != '%' && !conv_struc->cf_zero && n_prec >= 0 &&
	(n_space = conv_struc->c_width - (n_prec + ft_strlen(str))) > 0)
	{
		if ((conv_struc->cf_space || conv_struc->cf_plus) &&
		(conv_spec == 'd' || conv_spec == 'i') &&
		(is_digit(str[0]) || str[0] == '\0'))
			n_space -= 1;
		if ((conv_struc->cf_sharp && (conv_spec == 'x' || conv_spec == 'X')) ||
		conv_spec == 'p')
			n_space -= 2;
		return (filler_line(space_str, n_space, ' '));
	}
	return (0);
}

int	space_line_s(char **space_str, t_conv *conv_struc, int n_prec)
{
	int		n_space;

	n_space = 0;
	if (n_prec >= 0 && (n_space = conv_struc->c_width - n_prec) > 0)
		return (filler_line(space_str, n_space, ' '));
	return (0);
}
