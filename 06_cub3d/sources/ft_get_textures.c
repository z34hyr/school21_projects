/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:40:00 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/15 01:37:16 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_fill_textr(t_game *exe, t_image *textr, char *path)
{
	int width;
	int height;

	if (!(textr->img = mlx_xpm_file_to_image(exe->mlx, path,
	&width, &height)))
		return (0);
	textr->width = width;
	textr->height = height;
	textr->addr =
	mlx_get_data_addr(textr->img,
	&textr->bits_per_pixel,
	&textr->line_length,
	&textr->endian);
	return (1);
}

void	ft_get_textures(t_game *exe)
{
	if (!ft_fill_textr(exe, &exe->textr[0], exe->no_path))
		ft_write_message(MSG_CANT_OPEN_NPIC);
	if (!ft_fill_textr(exe, &exe->textr[1], exe->so_path))
		ft_write_message(MSG_CANT_OPEN_SPIC);
	if (!ft_fill_textr(exe, &exe->textr[2], exe->ea_path))
		ft_write_message(MSG_CANT_OPEN_EPIC);
	if (!ft_fill_textr(exe, &exe->textr[3], exe->we_path))
		ft_write_message(MSG_CANT_OPEN_WPIC);
	if (!ft_fill_textr(exe, &exe->spr_textr, exe->s_path))
	{
		perror(ERR_CANT_OPEN_SPPIC);
		exit(1);
	}
}
