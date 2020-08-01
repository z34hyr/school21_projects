/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_spec_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:23:30 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/25 00:52:25 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long int	ft_div_16(unsigned long int num, char conv_case)
{
	if (num > 9 && num < 16)
	{
		if (conv_case == 'x' || conv_case == 'p')
			num += 87;
		else if (conv_case == 'X')
			num += 55;
	}
	else
		num += 48;
	return (num);
}

int					ft_copy_backward(char **dst, char *src)
{
	int i;
	int j;

	j = -1;
	i = ft_strlen(src);
	if (!(*dst = (char*)malloc(i + 1)))
		return (0);
	while (j++ < i - 1)
		*(*dst + j) = src[i - j - 1];
	*(*dst + j) = '\0';
	return (1);
}

char				*hex_line(t_conv *conv_struc, va_list a)
{
	unsigned long int	z;
	char				p[20];
	int					i;
	char				conv_case;
	char				*res_line;

	i = 0;
	if (conv_struc->cs == 'p')
		z = (unsigned long int)va_arg(a, unsigned long int);
	else
		z = (unsigned int)va_arg(a, unsigned int);
	res_line = NULL;
	conv_case = conv_struc->cs;
	while (z / 16)
	{
		p[i] = ft_div_16(z % 16, conv_case);
		z /= 16;
		i += 1;
	}
	p[i] = ft_div_16(z, conv_case);
	p[i + 1] = '\0';
	if (!ft_copy_backward(&res_line, p))
		return (NULL);
	return (res_line);
}
