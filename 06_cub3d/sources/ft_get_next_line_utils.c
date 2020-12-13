/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 02:32:17 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 02:32:21 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** result - buf_size (if there is no \n), or number of symbols include \n
** or number of symbols before \0 (if we have buffer remainder)
** Also changing \n to \0 to simplify copying in other functions.
*/

int		find_enter(char *buffer, int buf_size)
{
	int counter;

	counter = 0;
	if (buffer[0] == '\0')
		return (1);
	while (counter < buf_size - 1 && buffer[counter] != '\n' \
	&& buffer[counter] != '\0')
		counter += 1;
	if (buffer[counter] == '\0')
		return (counter);
	if (buffer[counter] == '\n')
		buffer[counter] = '\0';
	counter += 1;
	return (counter);
}

/*
** copying line (if line exists) to temporary line,
** then freeing memory allocated for line
** if we're doing this, that means we haven't reached yet the \n or EOF
** After that we add N (equal counter)symbols from buffer
*/

void	ft_copy_ex_line(char *temp_line, char **line, int line_len)
{
	int i;

	if (line_len)
	{
		i = 0;
		while (i < line_len)
		{
			temp_line[i] = *(*line + i);
			i += 1;
		}
		free(*line);
		*line = NULL;
	}
}

/*
** Addind to the temporary line part of buffer
** (N symbols, equal counter from "find_enter" function)
*/

void	ft_copy_from_buf(char *temp_line, char *buffer, int start_p, int end_p)
{
	int i;

	i = 0;
	while (i < end_p)
	{
		temp_line[start_p + i] = buffer[i];
		i += 1;
	}
}

/*
** Copying temporary line to output line
*/

void	ft_copy_new_line(char **new_line, char *temp_line, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		*(*new_line + i) = temp_line[i];
		i += 1;
	}
	free(temp_line);
	temp_line = NULL;
}

/*
** rigth hand of ft_get_next_line function.
** this function is responsible for memory allocation respectively find_n
** copying bytes to line and shifting them in buffer then.
*/

int		ft_copy(char *buffer, char **line, int buf_size, int line_len)
{
	int		eof;
	int		find_n;
	char	*temp_line;

	if (buffer[0] == '\0')
		eof = 0;
	else
		eof = 1;
	find_n = find_enter(buffer, buf_size);
	if (!(temp_line = (char*)malloc(find_n + line_len)))
		return (-1);
	ft_copy_ex_line(temp_line, line, line_len);
	ft_copy_from_buf(temp_line, buffer, line_len, find_n);
	if (!(*line = (char*)malloc(find_n + line_len)))
		return (-1);
	ft_copy_new_line(line, temp_line, find_n + line_len);
	ft_buff_shift(buffer, find_n, buf_size);
	return (find_n * eof);
}
