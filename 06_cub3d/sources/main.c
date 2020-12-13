/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 00:54:47 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 14:53:06 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*exe;

	if (!ft_check_argc(argc, argv) ||
	!(exe = ft_exe_struct(argv)))
		return (0);
	ft_prep_to_loop(exe, argc);
	ft_make_frame(exe);
	mlx_loop(exe->mlx);
	return (0);
}
