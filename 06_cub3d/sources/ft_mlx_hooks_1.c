/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hooks_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 21:02:47 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 02:52:52 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_forw(t_game *exe)
{
	if (exe->map_darray[(int)(exe->pos_x + exe->dir_x * MOVE_STEP)]
	[(int)(exe->pos_y)] == '0' &&
	(exe->map_darray[(int)exe->pos_x]
	[(int)(exe->pos_y + exe->dir_y * MOVE_STEP)] == '0'))
	{
		exe->pos_x += exe->dir_x * MOVE_STEP;
		exe->pos_y += exe->dir_y * MOVE_STEP;
	}
	else
		ft_strwrite("collision while moving forward");
}

void	ft_move_backw(t_game *exe)
{
	if (exe->map_darray[(int)(exe->pos_x - exe->dir_x * MOVE_STEP)]
	[(int)(exe->pos_y)] == '0' &&
	(exe->map_darray[(int)exe->pos_x]
	[(int)(exe->pos_y - exe->dir_y * MOVE_STEP)] == '0'))
	{
		exe->pos_x -= exe->dir_x * MOVE_STEP;
		exe->pos_y -= exe->dir_y * MOVE_STEP;
	}
	else
		ft_strwrite("collision while moving backward");
}

void	ft_step_left(t_game *exe)
{
	double x_cur;
	double y_cur;

	x_cur = (exe->dir_y > 0 ? -1.0 : 1.0);
	y_cur = (exe->dir_x > 0 ? 1.0 : -1.0);
	if (exe->map_darray
	[(int)(exe->pos_x + x_cur * fabs(exe->dir_y) * MOVE_STEP)]
	[(int)(exe->pos_y)] == '0' &&
	(exe->map_darray[(int)exe->pos_x]
	[(int)(exe->pos_y + y_cur * fabs(exe->dir_x) * MOVE_STEP)] == '0'))
	{
		exe->pos_x += x_cur * fabs(exe->dir_y) * MOVE_STEP;
		exe->pos_y += y_cur * fabs(exe->dir_x) * MOVE_STEP;
	}
	else
		ft_strwrite("collision while stepping left");
}

void	ft_step_rigth(t_game *exe)
{
	double x_cur;
	double y_cur;

	x_cur = (exe->dir_y > 0 ? 1.0 : -1.0);
	y_cur = (exe->dir_x > 0 ? -1.0 : 1.0);
	if (exe->map_darray
	[(int)(exe->pos_x + x_cur * fabs(exe->dir_y) * MOVE_STEP)]
	[(int)(exe->pos_y)] == '0' &&
	(exe->map_darray[(int)exe->pos_x]
	[(int)(exe->pos_y + y_cur * fabs(exe->dir_x) * MOVE_STEP)] == '0'))
	{
		exe->pos_x += x_cur * fabs(exe->dir_y) * MOVE_STEP;
		exe->pos_y += y_cur * fabs(exe->dir_x) * MOVE_STEP;
	}
	else
		ft_strwrite("collision while stepping right");
}

int		ft_my_key_hook(int key, t_game *exe)
{
	if (key == 65307)
		ft_close_window(key, exe);
	if (key == MOVE_FORWARD)
		ft_move_forw(exe);
	if (key == MOVE_LEFT)
		ft_step_left(exe);
	if (key == MOVE_BACKW)
		ft_move_backw(exe);
	if (key == MOVE_RIGHT)
		ft_step_rigth(exe);
	if (key == LOOK_LEFT)
		ft_rot_left(exe);
	if (key == LOOK_RIGHT)
		ft_rot_right(exe);
	ft_make_frame(exe);
	return (0);
}
