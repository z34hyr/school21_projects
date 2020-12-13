/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast_sprite_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:39:50 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 19:56:45 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_sort_sprays(t_game *exe)
{
	float	dist_curr;
	int		i;

	i = 0;
	while (i < exe->spr_count - 1)
	{
		if (exe->sprite_dist[i + 1] > exe->sprite_dist[i])
		{
			dist_curr = exe->sprite_dist[i + 1];
			exe->sprite_dist[i + 1] = exe->sprite_dist[i];
			exe->sprite_dist[i] = dist_curr;
			exe->sprite_order[i + 1] = exe->sprite_order[i] + 1;
			exe->sprite_order[i] = i;
			i = -1;
		}
		i += 1;
	}
}

static void	ft_add_pos(t_game *exe, int k, int i, int j)
{
	exe->sprite_darr[k][0] = j + 0.5;
	exe->sprite_darr[k][1] = i + 0.5;
	exe->sprite_order[k] = k;
}

void		ft_fill_sprite_arr(t_game *exe)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (exe->map_darray[j])
	{
		while (exe->map_darray[j][i])
		{
			if (exe->map_darray[j][i] == '2')
			{
				if (!(exe->sprite_darr[k] =
				(double*)malloc(sizeof(double) * 2)))
					exit(1);
				ft_add_pos(exe, k, i, j);
				k += 1;
			}
			i += 1;
		}
		i = 0;
		j += 1;
	}
}

void		ft_fill_sprite_darr(t_game *exe)
{
	if (exe->spr_count && !(exe->sprite_darr =
	(double**)malloc(sizeof(double*) * exe->spr_count)))
		exit(1);
	ft_fill_sprite_arr(exe);
}

void		ft_get_sprite_count(t_game *exe)
{
	int	i;
	int	j;

	exe->spr_count = 0;
	i = 0;
	j = 0;
	while (exe->map_darray[j])
	{
		while (exe->map_darray[j][i])
		{
			if (exe->map_darray[j][i] == '2')
				exe->spr_count += 1;
			i += 1;
		}
		i = 0;
		j += 1;
	}
	if (exe->spr_count)
	{
		if (!(exe->sprite_dist = (double*)malloc(sizeof(double) *
		exe->spr_count)) ||
		!(exe->sprite_order = (int*)malloc(sizeof(int) * exe->spr_count)))
			exit(1);
	}
	ft_fill_sprite_darr(exe);
}
