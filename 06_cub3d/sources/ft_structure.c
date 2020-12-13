/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:45:54 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 03:22:22 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game	*init_struct(void)
{
	t_game *map_struct;

	if (!(map_struct = malloc(sizeof(t_game))))
	{
		ft_write_message(ERR_STR_INIT);
		return (NULL);
	}
	map_struct->no_path = NULL;
	map_struct->so_path = NULL;
	map_struct->ea_path = NULL;
	map_struct->we_path = NULL;
	map_struct->s_path = NULL;
	map_struct->map_list = NULL;
	map_struct->map_darray = NULL;
	map_struct->pos_x = -1;
	map_struct->pos_y = -1;
	ft_write_message(MSG_STR_INIT_OK);
	return (map_struct);
}

void	ft_free_struct(t_game *map_struct)
{
	if (map_struct)
	{
		if (map_struct->no_path)
			free(map_struct->no_path);
		if (map_struct->so_path)
			free(map_struct->so_path);
		if (map_struct->ea_path)
			free(map_struct->ea_path);
		if (map_struct->we_path)
			free(map_struct->we_path);
		if (map_struct->s_path)
			free(map_struct->s_path);
		if (map_struct->map_list)
			ft_lstclear(&(map_struct->map_list), (void*)&ft_free_str);
		if (map_struct->map_darray)
			ft_free_darray(map_struct->map_darray);
		free(map_struct);
		map_struct = NULL;
	}
}
