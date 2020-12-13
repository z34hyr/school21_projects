/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:30:52 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 19:58:14 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_camera_init(t_camera *ray, t_game *exe)
{
	ray->camera_x = 2 * (double)ray->x / (double)exe->res[0] - 1;
	ray->ray_dir_x = exe->dir_x + exe->plane_x * ray->camera_x;
	ray->ray_dir_y = exe->dir_y + exe->plane_y * ray->camera_x;
	ray->map_x = (int)exe->pos_x;
	ray->map_y = (int)exe->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	ft_get_dist(t_camera *ray, t_game *exe)
{
	ray->collis = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (exe->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - exe->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (exe->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - exe->pos_y) * ray->delta_dist_y;
	}
}

void	ft_find_collis(t_camera *ray, t_game *exe)
{
	while (ray->collis == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (exe->map_darray[ray->map_x][ray->map_y] - 48 == 1)
			ray->collis = 1;
	}
	ft_get_card_point(ray, exe);
}

void	ft_get_wall_height(t_camera *ray, t_game *exe)
{
	if (ray->side == 0)
		ray->perp_wall_dist =
		(ray->map_x - exe->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist =
		(ray->map_y - exe->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(exe->res[1] / ray->perp_wall_dist);
	ray->draw_start = (int)(-ray->line_height / DIST +
	(double)exe->res[1] / DIST);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (int)(ray->line_height / DIST +
	(double)exe->res[1] / DIST);
	if (ray->draw_end >= exe->res[1])
		ray->draw_end = exe->res[1] - 1;
}

void	ft_draw_perp(t_game *exe)
{
	t_camera *ray;

	if (!(ray = (t_camera*)malloc(sizeof(t_camera))))
		exit(1);
	ray->x = 0;
	exe->img1.addr =
	mlx_get_data_addr(exe->img1.img, &exe->img1.bits_per_pixel,
	&exe->img1.line_length, &exe->img1.endian);
	while (ray->x < exe->res[0])
	{
		ft_camera_init(ray, exe);
		ft_get_dist(ray, exe);
		ft_find_collis(ray, exe);
		ft_get_wall_height(ray, exe);
		if (exe->textr[exe->curr_side].img)
			ft_get_textr_color(ray, exe);
		else
			ft_draw_line(exe, ray);
		exe->dist_array[ray->x] = ray->perp_wall_dist;
		ray->x += 1;
	}
	ft_draw_sprite(exe);
	free(ray);
	ray = NULL;
}
