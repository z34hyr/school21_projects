/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 02:51:03 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 03:18:08 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_rot_right(t_game *exe)
{
	double dir_x0;
	double plane_x0;

	dir_x0 = exe->dir_x;
	plane_x0 = exe->plane_x;
	exe->dir_x = exe->dir_y * sin(ROT_STEP) + dir_x0 * cos(ROT_STEP);
	exe->dir_y = exe->dir_y * cos(ROT_STEP) - dir_x0 * sin(ROT_STEP);
	exe->plane_x = exe->plane_y * sin(ROT_STEP) + plane_x0 * cos(ROT_STEP);
	exe->plane_y = exe->plane_y * cos(ROT_STEP) - plane_x0 * sin(ROT_STEP);
}

void	ft_rot_left(t_game *exe)
{
	double dir_x0;
	double plane_x0;

	dir_x0 = exe->dir_x;
	plane_x0 = exe->plane_x;
	exe->dir_x = exe->dir_y * sin(-ROT_STEP) + dir_x0 * cos(-ROT_STEP);
	exe->dir_y = exe->dir_y * cos(-ROT_STEP) - dir_x0 * sin(-ROT_STEP);
	exe->plane_x = exe->plane_y * sin(-ROT_STEP) + plane_x0 * cos(-ROT_STEP);
	exe->plane_y = exe->plane_y * cos(-ROT_STEP) - plane_x0 * sin(-ROT_STEP);
}
