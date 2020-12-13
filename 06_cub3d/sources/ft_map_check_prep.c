/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check_prep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:44:23 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 15:34:46 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_darr_len(char **darray)
{
	int i;

	i = 0;
	while (darray && darray[i])
		i += 1;
	return (i);
}

char	*ft_get_poss_arr(char symb)
{
	if (symb == '1')
		return (POSS_1_NEIB);
	if (symb == '0' || symb == '2' || symb == 'N' ||
		symb == 'S' || symb == 'W' || symb == 'E')
		return (POSS_02_NSWE_NEIB);
	if (symb == ' ')
		return (POSS_SPACE_NEIB);
	return (NULL);
}

int		ft_check_line_validity(char **map_darr, int curr_line,
int *is_gamer_here)
{
	int		i;
	char	*poss_symb;

	i = -1;
	while (map_darr[curr_line][++i])
	{
		if (!(poss_symb = ft_get_poss_arr(map_darr[curr_line][i])))
		{
			ft_write_message(ERR_MAP_BAD_CHAR);
			return (0);
		}
		if (!ft_check_right(map_darr[curr_line], i, poss_symb, is_gamer_here)
		|| !ft_check_left(map_darr[curr_line], i, poss_symb)
		|| !ft_check_up(map_darr, i, curr_line, poss_symb)
		|| !ft_check_down(map_darr, i, curr_line, poss_symb))
			return (0);
	}
	return (1);
}

int		ft_check_map(char **map_darray)
{
	int i;
	int is_gamer_here;

	i = -1;
	is_gamer_here = 0;
	while (map_darray[++i])
	{
		if (!ft_check_line_validity(map_darray, i, &is_gamer_here))
			return (0);
	}
	if (is_gamer_here == 1)
	{
		ft_write_message(MSG_MAP_IS_OK);
		return (1);
	}
	ft_write_message(ERR_MAP_NO_PLAYER);
	return (0);
}
