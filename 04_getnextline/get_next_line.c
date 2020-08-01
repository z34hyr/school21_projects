/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 07:42:52 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/01 03:06:05 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** compile as
** gcc -Wall -Wextra -Werror -D
** BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
** gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
*/

/*
** this one clears buffer from start to the end of buffer
** so if we're clearing from the beginning, then we red whole buffer
*/

void	ft_buff_nclean(char *buffer, int start, int n)
{
	while (start < n)
		buffer[start++] = '\0';
}

/*
** shift buffer from buffer[shift_len + i] character to the
** beginning of buffer
*/

int		ft_buff_shift(char *buffer, int shift_len, int buff_size)
{
	int i;

	i = 0;
	while (i < buff_size - shift_len)
	{
		buffer[i] = buffer[shift_len + i];
		i += 1;
	}
	ft_buff_nclean(buffer, buff_size - shift_len, buff_size);
	return (shift_len);
}

/*
** static char initialized as '\0' by compilator
** and stores in BSS
** for valgrind:
** valgrind --leak-check=full --leak-resolution=med ./a.out
*/

int		get_next_line(int fd, char **line)
{
	static char	p[BUFFER_SIZE];
	int			find_n;
	int			line_len;
	int			read_res;

	find_n = 0;
	line_len = 0;
	read_res = -2;
	if (!line || fd < 0 || BUFFER_SIZE == 0)
		return (-1);
	while (p[0] != '\0' || ((read_res = read(fd, p, BUFFER_SIZE)) >= 0))
	{
		find_n = ft_copy(p, line, BUFFER_SIZE, line_len);
		line_len += find_n;
		if (find_n > 0 && *(*line + line_len - 1) == '\0')
			return (1);
		else if (find_n == 0)
			return (0);
		else if (find_n == -1)
			return (-1);
	}
	return (-1);
}
