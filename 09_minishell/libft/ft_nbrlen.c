/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarguri <rmarguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:08:28 by rmarguri          #+#    #+#             */
/*   Updated: 2020/08/21 16:41:40 by rmarguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int i;

	if (n == 0)
		return (1);
	else
	{
		i = 0;
		while (n != 0)
		{
			n /= 10;
			i++;
		}
	}
	return (i);
}