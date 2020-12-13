/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:06:30 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/23 00:20:30 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_special_d_i(char *str, t_conv *cnv_st)
{
	if (str[0] == '-')
		return (write(1, "-", 1));
	else if (cnv_st->cf_plus && (cnv_st->cs == 'd' || cnv_st->cs == 'i'))
		return (write(1, "+", 1));
	else
		return (0);
}

int			print_d_i_u_x(char *pr_str, char *sp_str, char *str, t_conv *cnv_st)
{
	int n_write;

	n_write = 0;
	if (cnv_st->cf_space && str[0] != '-' &&
	(cnv_st->cs == 'd' || cnv_st->cs == 'i'))
		n_write += write(1, " ", 1);
	if (cnv_st->cf_minus == 0 && sp_str)
		n_write += write(1, sp_str, ft_strlen(sp_str));
	n_write += print_special_d_i(str, cnv_st);
	if (cnv_st->cs == 'p' || (cnv_st->cs == 'x' && cnv_st->cf_sharp))
		n_write += write(1, "0x", 2);
	if (cnv_st->cs == 'X' && cnv_st->cf_sharp)
		n_write += write(1, "0X", 2);
	if (pr_str)
		n_write += write(1, pr_str, ft_strlen(pr_str));
	if (str[0] != '-')
		n_write += write(1, str, ft_strlen(str));
	else
		n_write += write(1, str + 1, ft_strlen(str) - 1);
	if (cnv_st->cf_minus == 1 && sp_str)
		n_write += write(1, sp_str, ft_strlen(sp_str));
	free_flags_str(pr_str, sp_str);
	return (n_write);
}

int			print_s(int n_prec, char *space_str, char *str, int minus)
{
	int n_write;

	n_write = 0;
	if (minus == 0 && space_str)
		n_write += write(1, space_str, ft_strlen(space_str));
	n_write += write(1, str, n_prec);
	if (minus == 1 && space_str)
		n_write += write(1, space_str, ft_strlen(space_str));
	free_flags_str(NULL, space_str);
	return (n_write);
}

void		to_flag_func(t_conv *conv_struc, va_list a, int *counter)
{
	int res;

	res = 0;
	if (conv_struc->cs == 'd' || conv_struc->cs == 'i')
		res = flag_d_i(conv_struc, a);
	else if (conv_struc->cs == 'u')
		res = flag_u(conv_struc, a);
	else if (conv_struc->cs == 'c')
		res = flag_c(conv_struc, a);
	else if (conv_struc->cs == 'x' || conv_struc->cs == 'X')
		res = flag_x(conv_struc, a);
	else if (conv_struc->cs == 's')
		res = flag_s(conv_struc, a);
	else if (conv_struc->cs == 'p')
		res = flag_p(conv_struc, a);
	else if (conv_struc->cs == '%')
		res = flag_percent();
	else if (conv_struc->cs == 'n')
		flag_n(*counter, a);
	if (res == -1)
		*counter = -1;
	else
		*counter += res;
	free(conv_struc);
	conv_struc = NULL;
}
