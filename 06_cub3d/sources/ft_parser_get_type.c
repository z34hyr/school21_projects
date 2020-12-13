/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_type.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 00:09:14 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 21:13:10 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_get_path(char *str, int *i, int type, t_game *param_str)
{
	char	*path;
	int		k;

	ft_skip_space(str, i);
	k = *i;
	while (str[*i] != '\0' && str[*i] != ' ' &&
	str[*i] >= 33 && str[*i] <= 126)
		*i += 1;
	if (!(path = (char*)malloc(sizeof(char) * (*i - k) + 1)))
		return (-1);
	ft_strlcpy(path, &str[k], *i - k + 1);
	if (type == TYPE_NO)
		param_str->no_path = path;
	if (type == TYPE_WE)
		param_str->we_path = path;
	if (type == TYPE_SO)
		param_str->so_path = path;
	if (type == TYPE_EA)
		param_str->ea_path = path;
	if (type == TYPE_S)
		param_str->s_path = path;
	return (0);
}

int	ft_get_resolution(char *str, int *i, t_game *param_str)
{
	int width;
	int height;

	if ((width = ft_spec_atoui(str, i, 1, 65535)) == -1)
		return (-1);
	if ((height = ft_spec_atoui(str, i, 1, 65535)) == -1)
		return (-1);
	param_str->res[0] = width;
	param_str->res[1] = height;
	if (str[*i] != ' ' && str[*i] != '\0')
		return (0);
	return (1);
}

int	ft_spec_atoui(char *str, int *i, int diap_min, int diap_max)
{
	int number;

	number = -1;
	ft_skip_space(str, i);
	while (str[*i] && str[*i] == '0')
	{
		number = 0;
		*i += 1;
	}
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		if (number == -1)
			number = str[*i] - '0';
		else
			number = number * 10 + str[*i] - '0';
		*i += 1;
	}
	if (number < diap_min || number > diap_max)
	{
		ft_write_message(ERR_WRONG_DIAP);
		return (-1);
	}
	return (number);
}

int	ft_get_color(char *str, int *i, int type, t_game *param_str)
{
	int r;
	int g;
	int b;
	int *dest;

	if ((r = ft_spec_atoui(str, i, 0, 255)) == -1 ||
	(str[*i] && str[*i + 1] && str[*i] != ','))
		return (-1);
	*i += 1;
	if ((g = ft_spec_atoui(str, i, 0, 255)) == -1 ||
	(str[*i] && str[*i + 1] && str[*i] != ','))
		return (-1);
	*i += 1;
	if ((b = ft_spec_atoui(str, i, 0, 255)) == -1)
		return (-1);
	if (type == TYPE_F)
		dest = param_str->color_floor;
	if (type == TYPE_C)
		dest = param_str->color_ceiling;
	dest[0] = r;
	dest[1] = g;
	dest[2] = b;
	if (str[*i] != ' ' && str[*i] != '\0')
		return (0);
	return (1);
}

int	ft_get_type(char *str, int *i, unsigned int *param_set, t_game *param_str)
{
	unsigned int type;

	ft_skip_space(str, i);
	type = 0;
	if (str[*i] && (type = ft_is_enabled_type(str, i)) == 0b00000011u)
		return (-1);
	else if (type > 0 && type < 0b00010000u)
		*i += 3;
	else if (str[*i] && type >= 0b00010000u)
		*i += 2;
	if (*param_set > 0 && type > 0 && (*param_set & type))
	{
		ft_write_message(ERR_DUPLICATE_TYPES);
		return (-1);
	}
	*param_set |= type;
	if (ft_fill_type(str, i, type, param_str) == -1)
	{
		ft_write_message(ERR_WRONG_TYPE_ARGS);
		return (-1);
	}
	return (1);
}
