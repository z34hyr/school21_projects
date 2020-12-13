/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_sc_perc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:09:51 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/25 00:27:58 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_c(t_conv *conv_struc, va_list a)
{
	unsigned char	c;
	int				n_space;
	int				n_write;
	char			*space_str;

	c = (unsigned char)va_arg(a, int);
	n_write = 0;
	space_str = NULL;
	n_space = filler_line(&space_str, conv_struc->c_width - 1, ' ');
	if (n_space >= 0)
	{
		if (space_str && !conv_struc->cf_minus)
			n_write += write(1, space_str, ft_strlen(space_str));
		n_write += write(1, &c, 1);
		if (space_str && conv_struc->cf_minus)
			n_write += write(1, space_str, ft_strlen(space_str));
		free_flags_str(NULL, space_str);
	}
	else
		n_write = -1;
	return (n_write);
}

int	flag_s(t_conv *conv_struc, va_list a)
{
	char	*str;
	int		n_prec;
	int		n_space;
	int		n_write;
	char	*space_str;

	space_str = NULL;
	n_write = 0;
	n_prec = 0;
	str = va_arg(a, char*);
	if (str == NULL && (!conv_struc->cf_dot || (conv_struc->cf_dot &&
	(conv_struc->prec_width >= 6 || conv_struc->prec_width < 0))))
		str = "(null)";
	else if (str == NULL && conv_struc->prec_width < 6)
		str = "";
	n_prec = prec_line_s(str, conv_struc);
	n_space = space_line_s(&space_str, conv_struc, n_prec);
	if (n_prec >= 0 && n_space >= 0)
		n_write = print_s(n_prec, space_str, str, conv_struc->cf_minus);
	else
		free_by_err(NULL, space_str, &n_write);
	return (n_write);
}

int	flag_percent(void)
{
	write(1, "%", 1);
	return (1);
}
