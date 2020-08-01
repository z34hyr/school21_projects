/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 01:49:05 by qmalcom           #+#    #+#             */
/*   Updated: 2020/07/01 01:51:24 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 256
# endif

void	ft_buff_nclean(char *buffer, int start, int n);
int		ft_buff_shift(char *buffer, int shift_len, int buff_size);
int		get_next_line(int fd, char **line);
int		ft_copy(char *buffer, char **line, int buf_size, int line_len);

#endif
