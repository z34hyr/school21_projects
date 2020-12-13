/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 11:42:12 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 22:21:01 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game	*ft_exe_struct(char **argv)
{
	int		fd;
	int		i;
	t_game	*exe;

	exe = NULL;
	if ((fd = ft_open_params_file(argv[1])) == -1 ||
	!(exe = init_struct()) ||
	ft_parameters_parser(fd, exe) == -1 ||
	!(exe->map_list = ft_get_map_list(fd)) ||
	!(exe->map_darray = ft_get_map_darray(exe->map_list)) ||
	!ft_check_map(exe->map_darray) ||
	!(exe->mlx = mlx_init()))
		exit(1);
	i = -1;
	while (++i < 3)
	{
		exe->fl_color += exe->color_floor[i] << (2 - i) * 8;
		exe->ceil_color += exe->color_ceiling[i] << (2 - i) * 8;
	}
	return (exe);
}

int		ft_check_resolution(t_game *exe)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	mlx_get_screen_size(exe->mlx, &w, &h);
	if (exe->res[0] > w)
		exe->res[0] = w;
	if (exe->res[1] > h)
		exe->res[1] = h;
	return (1);
}

int		ft_close_window(int keycode, t_game *exe)
{
	exe->skip = keycode;
	ft_strwrite("Bye-bye!");
	exit(1);
}

void	ft_my_pixel_put(t_game *exe, int x, int y, int color)
{
	char	*dst;

	dst = exe->img1.addr + (y * exe->img1.line_length +
	x * (exe->img1.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_get_color_z(t_image textr, int x, int y)
{
	char	*dst;
	int		color;

	dst = textr.addr + (y * textr.line_length +
	x * (textr.bits_per_pixel / 8));
	color = *(unsigned int*)dst;
	return (color);
}
