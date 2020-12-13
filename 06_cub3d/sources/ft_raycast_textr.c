/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_textr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:05:57 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 19:56:04 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** current cardinal point curr_side
** 0 = 'N'
** 1 = 'S'
** 2 = 'E'
** 3 = 'W'
*/

int		ft_make_frame(t_game *exe)
{
	if (exe->img1.img)
		mlx_destroy_image(exe->mlx, exe->img1.img);
	exe->img1.img = mlx_new_image(exe->mlx, exe->res[0], exe->res[1]);
	ft_fill_half(exe);
	ft_draw_perp(exe);
	mlx_put_image_to_window(exe->mlx, exe->win, exe->img1.img, 0, 0);
	return (0);
}

void	ft_get_card_point(t_camera *ray, t_game *exe)
{
	if (ray->ray_dir_x > 0 && !ray->side)
		exe->curr_side = 1;
	if (ray->ray_dir_x < 0 && !ray->side)
		exe->curr_side = 0;
	if (ray->ray_dir_y > 0 && ray->side)
		exe->curr_side = 2;
	if (ray->ray_dir_y < 0 && ray->side)
		exe->curr_side = 3;
}

void	ft_get_textr_coord(t_camera *ray, t_game *exe)
{
	if (ray->side == 0)
		ray->wall_coord = exe->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_coord = exe->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_coord -= floor(ray->wall_coord);
	ray->textr_coord_x = (int)(ray->wall_coord *
	exe->textr[exe->curr_side].width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) ||
	(ray->side != 0 && ray->ray_dir_y < 0))
		ray->textr_coord_x =
		exe->textr[exe->curr_side].width - ray->textr_coord_x - 1.0;
	ray->step = 1.0 * exe->textr[exe->curr_side].height / ray->line_height;
	ray->textr_pos =
	(ray->draw_start - exe->res[1] / DIST +
	ray->line_height / DIST) * ray->step;
}

void	ft_get_textr_color(t_camera *ray, t_game *exe)
{
	int start;
	int color;

	start = ray->draw_start - 1;
	ft_get_textr_coord(ray, exe);
	while (++start < ray->draw_end)
	{
		ray->textr_coord_y = (int)ray->textr_pos &
		(exe->textr[exe->curr_side].width - 1);
		ray->textr_pos += ray->step;
		color = ft_get_color_z(exe->textr[exe->curr_side],
		ray->textr_coord_x, ray->textr_coord_y);
		ft_my_pixel_put(exe, ray->x, start, color);
	}
}
