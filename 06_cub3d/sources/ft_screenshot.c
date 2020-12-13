/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screenshot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 02:25:35 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 20:00:13 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_scrsht	ft_scrsht_init(int w, int h)
{
	t_scrsht screen_shot;

	screen_shot.signature[0] = 'B';
	screen_shot.signature[1] = 'M';
	screen_shot.filesize = 54 + 4 * w * h;
	screen_shot.reserved = 0;
	screen_shot.offset = 54;
	screen_shot.header_size = 40;
	screen_shot.dimensions[0] = w;
	screen_shot.dimensions[1] = h;
	screen_shot.col_planes = 1;
	screen_shot.bpp = 32;
	screen_shot.compression = 0;
	screen_shot.img_size = w * h * 4;
	screen_shot.resolution[0] = 2795;
	screen_shot.resolution[1] = 2795;
	screen_shot.pltcolor = 0;
	screen_shot.impcolor = 0;
	return (screen_shot);
}

static void		ft_write_to_bmp(int fd2, t_scrsht *scrsht)
{
	write(fd2, (char*)scrsht->signature, sizeof(scrsht->signature));
	write(fd2, (char*)&scrsht->filesize, sizeof(scrsht->filesize));
	write(fd2, (char*)&scrsht->reserved, sizeof(scrsht->reserved));
	write(fd2, (char*)&scrsht->offset, sizeof(scrsht->offset));
	write(fd2, (char*)&scrsht->header_size, sizeof(scrsht->header_size));
	write(fd2, (char*)scrsht->dimensions, sizeof(scrsht->dimensions));
	write(fd2, (char*)&scrsht->col_planes, sizeof(scrsht->col_planes));
	write(fd2, (char*)&scrsht->bpp, sizeof(scrsht->bpp));
	write(fd2, (char*)&scrsht->compression, sizeof(scrsht->compression));
	write(fd2, (char*)&scrsht->img_size, sizeof(scrsht->img_size));
	write(fd2, (char*)scrsht->resolution, sizeof(scrsht->resolution));
	write(fd2, (char*)&scrsht->pltcolor, sizeof(scrsht->pltcolor));
	write(fd2, (char*)&scrsht->impcolor, sizeof(scrsht->impcolor));
}

void			ft_save_screen(t_game *exe)
{
	int			fd2;
	int			i;
	int			j;
	int			color;
	t_scrsht	scrsht;

	i = -1;
	j = exe->res[1];
	if (!(fd2 = open("first_frame.bmp", O_CREAT, 0644)))
		exit(1);
	close(fd2);
	scrsht = ft_scrsht_init(exe->res[0], exe->res[1]);
	fd2 = open("first_frame.bmp", O_WRONLY);
	ft_write_to_bmp(fd2, &scrsht);
	while (--j >= 0)
	{
		while (++i < exe->res[0])
		{
			color = ft_get_color_z(exe->img1, i, j);
			write(fd2, (char*)&color, sizeof(color));
		}
		i = -1;
	}
	close(fd2);
}
