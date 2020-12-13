/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_iduxp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:59:29 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/22 23:24:43 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_d_i(t_conv *conv_struc, va_list a)
{
	char	*str;
	int		n_write;
	int		n_prec;
	char	*prec_str;
	char	*space_str;

	prec_str = NULL;
	space_str = NULL;
	n_write = 0;
	n_prec = 0;
	if (!(str = ft_itoa(va_arg(a, int))))
		return (-1);
	if (conv_struc->cf_dot && conv_struc->prec_width == 0 && str[0] == '0')
		str[0] = '\0';
	if ((n_prec = prec_line_i_d_u(str, &prec_str, conv_struc)) >= 0 &&
	space_line(str, &space_str, conv_struc, n_prec) >= 0)
		n_write = print_d_i_u_x(prec_str, space_str, str, conv_struc);
	else
		free_by_err(prec_str, space_str, &n_write);
	free_before_exit(str);
	return (n_write);
}

int	flag_u(t_conv *conv_struc, va_list a)
{
	char	*str;
	int		n_write;
	int		n_prec;
	char	*prec_str;
	char	*space_str;

	prec_str = NULL;
	space_str = NULL;
	n_write = 0;
	n_prec = 0;
	if (!(str = ft_uitoa(va_arg(a, unsigned int))))
		return (-1);
	if (conv_struc->cf_dot && conv_struc->prec_width == 0 && str[0] == '0')
		str[0] = '\0';
	if ((n_prec = prec_line_i_d_u(str, &prec_str, conv_struc)) >= 0 &&
	space_line(str, &space_str, conv_struc, n_prec) >= 0)
		n_write = print_d_i_u_x(prec_str, space_str, str, conv_struc);
	else
		free_by_err(prec_str, space_str, &n_write);
	free_before_exit(str);
	return (n_write);
}

int	flag_x(t_conv *conv_struc, va_list a)
{
	char	*hex_str;
	int		n_write;
	int		n_prec;
	char	*prec_str;
	char	*space_str;

	hex_str = NULL;
	prec_str = NULL;
	space_str = NULL;
	n_write = 0;
	n_prec = 0;
	if (!(hex_str = hex_line(conv_struc, a)))
		return (-1);
	if (conv_struc->cf_dot && conv_struc->prec_width == 0 && hex_str[0] == '0')
		hex_str[0] = '\0';
	if ((n_prec = prec_line_i_d_u(hex_str, &prec_str, conv_struc)) >= 0 &&
	space_line(hex_str, &space_str, conv_struc, n_prec) >= 0)
		n_write = print_d_i_u_x(prec_str, space_str, hex_str, conv_struc);
	else
		free_by_err(prec_str, space_str, &n_write);
	free_before_exit(hex_str);
	return (n_write);
}

int	flag_p(t_conv *conv_struc, va_list a)
{
	char	*hex_str;
	int		n_space;
	int		n_write;
	char	*space_str;

	hex_str = NULL;
	space_str = NULL;
	n_write = 0;
	if (!(hex_str = hex_line(conv_struc, a)))
		return (-1);
	n_space = space_line(hex_str, &space_str, conv_struc, 0);
	if (n_space >= 0)
		n_write = print_d_i_u_x(NULL, space_str, hex_str, conv_struc);
	else
		free_by_err(NULL, space_str, &n_write);
	free_before_exit(hex_str);
	return (n_write);
}
