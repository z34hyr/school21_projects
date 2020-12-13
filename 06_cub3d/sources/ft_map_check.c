/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 23:48:18 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 15:42:21 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
** i - number of current symbol
** j - number of current line
** poss_sybm - array of possible symbols for checking char
*/

int	ft_check_left(char *curr_line, int i, char *poss_symb)
{
	if (i > 0 && !ft_strchr(poss_symb, curr_line[i - 1]))
	{
		ft_write_message(ERR_MAP_BAD_NEIGHBOR);
		return (0);
	}
	else if (i == 0 && curr_line[i] != '1' && curr_line[i] != ' ')
	{
		ft_write_message(ERR_MAP_BAD_BOL);
		return (0);
	}
	return (1);
}

int	ft_check_up(char **map_darray, int i, int j, char *poss_symb)
{
	int		len_up;

	if (j > 0)
		len_up = ft_strlen(map_darray[j - 1]);
	else
		len_up = -1;
	if ((i > 0 && len_up >= i + 1 &&
	!ft_strchr(poss_symb, map_darray[j - 1][i]))
	|| (len_up != 0 && len_up < i + 1 &&
	!ft_strchr(POSS_SIDE_CHAR, map_darray[j][i])))
		return (0);
	return (1);
}

int	ft_check_right(char *curr_line, int i, char *poss_symb, int *gamer)
{
	if (i < (int)ft_strlen(curr_line) - 1 &&
	!ft_strchr(poss_symb, curr_line[i + 1]))
	{
		ft_write_message(ERR_MAP_BAD_NEIGHBOR);
		return (0);
	}
	else if (i == (int)ft_strlen(curr_line) - 1
	&& curr_line[i] != '1'
	&& curr_line[i] != ' ')
	{
		ft_write_message(ERR_MAP_BAD_EOL);
		return (0);
	}
	if (ft_strchr(GAMER_CHAR, curr_line[i]))
		*gamer += 1;
	if (*gamer > 1)
	{
		ft_write_message(ERR_MAP_MANY_GAMERS);
		return (0);
	}
	return (1);
}

int	ft_check_down(char **map_darray, int i, int j, char *poss_symb)
{
	int		len_down;

	if (map_darray[j + 1])
		len_down = ft_strlen(map_darray[j + 1]);
	else
		len_down = -1;
	if (j + 1 == ft_darr_len(map_darray))
		len_down = -1;
	if ((len_down >= i + 1 &&
	!ft_strchr(poss_symb, map_darray[j + 1][i]))
	|| (len_down != 0 && len_down < i + 1 &&
	!ft_strchr(POSS_SIDE_CHAR, map_darray[j][i]))
	|| (len_down == 0))
	{
		ft_write_message(ERR_MAP_BAD_NEIGHBOR);
		return (0);
	}
	return (1);
}
