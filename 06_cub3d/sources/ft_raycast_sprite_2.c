/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_sprite_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 21:19:37 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/15 21:01:17 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_spr_param(t_game *exe, t_sprite *spr, int i)
{
	spr->sprite_x = exe->sprite_darr[exe->sprite_order[i]][0] - exe->pos_x;
	spr->sprite_y = exe->sprite_darr[exe->sprite_order[i]][1] - exe->pos_y;
	spr->inv_det = 1.0 /
	(exe->plane_x * exe->dir_y - exe->plane_y * exe->dir_x);
	spr->transf_x = spr->inv_det * (exe->dir_y * spr->sprite_x - exe->dir_x *
	spr->sprite_y);
	spr->transf_y = spr->inv_det * (-exe->plane_y * spr->sprite_x +
	exe->plane_x * spr->sprite_y);
	spr->sprite_scr_x = (int)((exe->res[0] / 2) *
	(1 + spr->transf_x / spr->transf_y));
	spr->sprite_height = abs((int)(exe->res[1] / spr->transf_y));
	spr->draw_start_y = -spr->sprite_height / 2 + exe->res[1] / 2;
	spr->draw_start_y = (spr->draw_start_y < 0 ? 0 : spr->draw_start_y);
	spr->draw_end_y = spr->sprite_height / 2 + exe->res[1] / 2;
	spr->draw_end_y =
	(spr->draw_end_y >= exe->res[1] ? exe->res[1] - 1 : spr->draw_end_y);
	spr->sprite_width = abs((int)(exe->res[0] / spr->transf_y));
	spr->draw_start_x = -spr->sprite_width / 2 + spr->sprite_scr_x;
	spr->draw_start_x = (spr->draw_start_x < 0 ? 0 : spr->draw_start_x);
	spr->draw_end_x = spr->sprite_width / 2 + spr->sprite_scr_x;
	spr->draw_end_x =
	(spr->draw_end_x >= exe->res[0] ? exe->res[0] - 1 : spr->draw_end_x);
	spr->line = spr->draw_start_x;
}

void	ft_draw_spr_line(t_game *exe, t_sprite *spr)
{
	while (spr->line < spr->draw_end_x)
	{
		spr->tex_x = (int)(256 *
		(spr->line - (-spr->sprite_width / 2 + spr->sprite_scr_x))
		* exe->spr_textr.width / spr->sprite_width) / 256;
		if (spr->transf_y > 0 && spr->line > 0 &&
		spr->line < exe->res[0] &&
		spr->transf_y < exe->dist_array[spr->line])
		{
			spr->y = spr->draw_start_y;
			while (spr->y < spr->draw_end_y)
			{
				spr->d = spr->y * 256 - exe->res[1] * 128
				+ spr->sprite_height * 128;
				spr->tex_y = ((spr->d * exe->spr_textr.height) /
				spr->sprite_height) / 256;
				spr->color = ft_get_color_z(exe->spr_textr, spr->tex_x,
				spr->tex_y);
				if (spr->color != 0)
					ft_my_pixel_put(exe, spr->line, spr->y, spr->color);
				spr->y += 1;
			}
		}
		spr->line += 1;
	}
}

void	ft_prep_spray(t_game *exe)
{
	int			i;
	t_sprite	spr;

	i = 0;
	while (i < exe->spr_count)
	{
		ft_get_spr_param(exe, &spr, i);
		ft_draw_spr_line(exe, &spr);
		i += 1;
	}
}

void	ft_draw_sprite(t_game *exe)
{
	int i;

	i = -1;
	while (++i < exe->spr_count)
	{
		exe->sprite_dist[i] = ((exe->pos_x - exe->sprite_darr[i][0]) *
				(exe->pos_x - exe->sprite_darr[i][0]) +
				(exe->pos_y - exe->sprite_darr[i][1]) *
				(exe->pos_y - exe->sprite_darr[i][1]));
	}
	ft_sort_sprays(exe);
	ft_prep_spray(exe);
}

void	ft_free_spr(t_game *exe)
{
	int i;

	i = 0;
	if (exe->sprite_order)
	{
		free(exe->sprite_order);
		exe->sprite_order = NULL;
	}
	if (exe->sprite_dist)
	{
		free(exe->sprite_dist);
		exe->sprite_dist = NULL;
	}
	if (exe->sprite_darr)
	{
		while (i < exe->spr_count)
		{
			free(exe->sprite_darr[i]);
			exe->sprite_darr[i] = NULL;
			i += 1;
		}
		free(exe->sprite_darr);
		exe->sprite_darr = NULL;
	}
}
