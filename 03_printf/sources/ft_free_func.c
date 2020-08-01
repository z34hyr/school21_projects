/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:26:27 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/22 22:47:26 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_flags_str(char *prec_str, char *space_str)
{
	if (prec_str)
	{
		free(prec_str);
		prec_str = NULL;
	}
	if (space_str)
	{
		free(space_str);
		space_str = NULL;
	}
}

void	free_by_err(char *prec_str, char *space_str, int *n_write)
{
	if (prec_str)
	{
		free(prec_str);
		prec_str = NULL;
	}
	if (space_str)
	{
		free(space_str);
		space_str = NULL;
	}
	*n_write = -1;
}

void	free_before_exit(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
