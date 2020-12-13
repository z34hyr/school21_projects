/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:21:15 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 21:12:50 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	ft_is_enabled_type(char *str, int *i)
{
	if (!ft_strncmp(&str[*i], STR_RES, 2))
		return (TYPE_RES);
	if (!ft_strncmp(&str[*i], STR_NO, 3))
		return (TYPE_NO);
	if (!ft_strncmp(&str[*i], STR_SO, 3))
		return (TYPE_SO);
	if (!ft_strncmp(&str[*i], STR_EA, 3))
		return (TYPE_EA);
	if (!ft_strncmp(&str[*i], STR_WE, 3))
		return (TYPE_WE);
	if (!ft_strncmp(&str[*i], STR_F, 2))
		return (TYPE_F);
	if (!ft_strncmp(&str[*i], STR_C, 2))
		return (TYPE_C);
	if (!ft_strncmp(&str[*i], STR_S, 2))
		return (TYPE_S);
	else
	{
		ft_write_message(ERR_WRONG_TYPE);
		return (0b00000011u);
	}
	return (1);
}

int				ft_fill_type(char *str, int *i, int type, t_game *param_str)
{
	if (type == TYPE_NO || type == TYPE_SO ||
	type == TYPE_EA || type == TYPE_WE || type == TYPE_S)
		return (ft_get_path(str, i, type, param_str));
	if (type == TYPE_F || type == TYPE_C)
		return (ft_get_color(str, i, type, param_str));
	if (type == TYPE_RES)
		return (ft_get_resolution(str, i, param_str));
	return (0);
}

static int		ft_gnl_res(int gnl_res, char *str)
{
	if (gnl_res == 0)
		ft_free_str(str);
	if (gnl_res == -1)
		return (-1);
	return (0);
}

int				ft_parameters_parser(int fd, t_game *map_params)
{
	char			*str;
	int				i;
	unsigned int	param_set;
	int				gnl_res;

	i = 0;
	param_set = 0b00000000u;
	str = NULL;
	while ((gnl_res = ft_get_next_line(fd, &str)) > 0)
	{
		while (str[i] && param_set != 0b11111111)
		{
			if (ft_get_type(str, &i, &param_set, map_params) == -1)
			{
				ft_free_str(str);
				return (-1);
			}
		}
		i = 0;
		ft_free_str(str);
		if (param_set == 0b11111111)
			break ;
	}
	return (ft_gnl_res(gnl_res, str));
}
