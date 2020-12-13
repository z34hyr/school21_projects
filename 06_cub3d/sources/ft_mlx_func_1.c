/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_func_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:42:12 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 19:55:01 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_prep_to_loop(t_game *exe, int argc)
{
	ft_check_resolution(exe);
	ft_get_textures(exe);
	ft_get_gamer_pos(exe);
	if (!(exe->dist_array = (double*)malloc(sizeof(double) * exe->res[0])))
		exit(1);
	ft_get_sprite_count(exe);
	exe->img1.img = mlx_new_image(exe->mlx, exe->res[0], exe->res[1]);
	ft_fill_half(exe);
	ft_draw_perp(exe);
	if (argc == 3)
	{
		ft_write_message(MSG_SCREENSHOT);
		ft_save_screen(exe);
		ft_write_message(MSG_SCR_OK);
		exit(0);
	}
	ft_win_init(exe);
}

int		ft_enter_window(t_game *exe)
{
	ft_make_frame(exe);
	return (0);
}

void	ft_win_init(t_game *exe)
{
	if (!(exe->win = mlx_new_window(exe->mlx, exe->res[0],
	exe->res[1], "Hello World! qmalcom's cub3d")))
		exit(1);
	mlx_hook(exe->win, 2, 1L << 0, ft_my_key_hook, exe);
	mlx_hook(exe->win, 12, 1L << 15, ft_enter_window, exe);
	mlx_hook(exe->win, 17, 1L << 17, ft_close_window, exe);
}

void	ft_fill_half(t_game *exe)
{
	int i;
	int j;
	int color;

	i = -1;
	j = -1;
	exe->img1.addr = mlx_get_data_addr(exe->img1.img,
			&exe->img1.bits_per_pixel,
			&exe->img1.line_length, &exe->img1.endian);
	while (++j < exe->res[1])
	{
		color = (j * DIST / exe->res[1] == 0 ? exe->ceil_color : exe->fl_color);
		while (++i < exe->res[0])
		{
			exe->img1.addr =
			mlx_get_data_addr(exe->img1.img, &exe->img1.bits_per_pixel,
			&exe->img1.line_length, &exe->img1.endian);
			ft_my_pixel_put(exe, i, j, color);
		}
		i = -1;
	}
}

/*
** current cardinal point curr_side
** 0 = 'N'
** 1 = 'S'
** 2 = 'E'
** 3 = 'W'
*/

void	ft_draw_line(t_game *exe, t_camera *ray)
{
	int y_curr;
	int color;

	exe->img1.addr =
	mlx_get_data_addr(exe->img1.img, &exe->img1.bits_per_pixel,
	&exe->img1.line_length, &exe->img1.endian);
	if (exe->curr_side == 0)
		color = 0x000000FF;
	if (exe->curr_side == 1)
		color = 0x00FF0000;
	if (exe->curr_side == 2)
		color = 0x0000FF00;
	if (exe->curr_side == 3)
		color = 0x00FFFFFF;
	y_curr = ray->draw_start - 1;
	while (++y_curr < ray->draw_end)
		ft_my_pixel_put(exe, ray->x, y_curr, color);
}
