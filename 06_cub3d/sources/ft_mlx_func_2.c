/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 02:47:53 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 03:19:02 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_gamer_pos(t_game *exe)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (exe->map_darray[j])
	{
		while (exe->map_darray[j][i])
		{
			if (ft_strchr(GAMER_CHAR, exe->map_darray[j][i]))
			{
				ft_set_gamer_pos(exe, i, j, exe->map_darray[j][i]);
				exe->map_darray[j][i] = '0';
			}
			i += 1;
		}
		i = 0;
		j += 1;
	}
}

void	ft_set_gamer_pos(t_game *exe, int i, int j, char way)
{
	exe->pos_x = (double)j + 0.5;
	exe->pos_y = (double)i + 0.5;
	if (way == 'N' || way == 'S')
		exe->dir_y = 0.0;
	if (way == 'E' || way == 'W')
		exe->dir_x = 0.0;
	if (way == 'N')
		exe->dir_x = -1.0;
	if (way == 'S')
		exe->dir_x = 1.0;
	if (way == 'W')
		exe->dir_y = -1.0;
	if (way == 'E')
		exe->dir_y = 1.0;
	exe->plane_x = (exe->dir_x == 0.0 ? exe->dir_y * FOV : 0.0);
	exe->plane_y = (exe->dir_y == 0.0 ? -exe->dir_x * FOV : 0.0);
}
