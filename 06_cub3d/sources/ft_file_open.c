/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_open.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:26:11 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/15 01:36:40 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_check_file_extension(char *file_name)
{
	int len;

	len = ft_strlen(file_name);
	if (len <= 4)
	{
		perror(ERR_WRONG_FILE_NAME);
		exit(1);
	}
	if (len > 4 && !ft_strncmp(&file_name[len - 4], FILE_EXTENSION, 4))
	{
		ft_write_message(MSG_FILE_EXT_OK);
		return (1);
	}
	else
	{
		perror(ERR_WRONG_FILE_EXT);
		exit(1);
	}
}

int			ft_open_params_file(char *file_path)
{
	int fd;

	if (!ft_check_file_extension(file_path))
		return (-1);
	fd = open(file_path, O_RDONLY);
	if (fd < 2)
	{
		perror(ERR_CANT_OPEN);
		exit(1);
	}
	else
	{
		ft_write_message(MSG_FILE_OPEN_OK);
		return (fd);
	}
}
