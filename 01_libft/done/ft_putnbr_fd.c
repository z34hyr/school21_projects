/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:42:32 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/09 15:22:22 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	min_int;

	min_int = 0;
	if (n == -2147483648)
	{
		min_int = 1;
		n /= 10;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n *= -1;
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar((char)(n % 10 + 48), fd);
	if (min_int)
		ft_putchar('8', fd);
}
