/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_darr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 02:18:33 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/14 21:38:25 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list	*ft_get_map_list(int fd)
{
	char	*str;
	t_list	*list;
	t_list	*start;
	int		gnl_res;

	start = NULL;
	while ((gnl_res = ft_get_next_line(fd, &str)) >= 0)
	{
		if (!start && ft_strlen(str) == 0 && gnl_res > 0)
		{
			ft_free_str(str);
			continue;
		}
		if (!(list = ft_lstnew(str)))
			return (NULL);
		ft_lstadd_back(&start, list);
		list = list->next;
		ft_free_str(str);
		if (gnl_res == 0)
			break ;
	}
	if (gnl_res == -1)
		return (NULL);
	return (start);
}

char	**ft_get_map_darray(t_list *map_list)
{
	int		i;
	char	**map_darray;

	map_darray = NULL;
	i = 0;
	if (!(map_darray = (char**)malloc(sizeof(char*) *
	(ft_lstsize(map_list) + 1))))
	{
		ft_write_message(ERR_MAP_DARR_CREATION);
		return (NULL);
	}
	while (map_list)
	{
		if (!(map_darray[i++] = ft_strdup(map_list->content)))
		{
			ft_write_message(ERR_MAP_DARR_CREATION);
			return (NULL);
		}
		map_list = map_list->next;
	}
	map_darray[i] = NULL;
	return (map_darray);
}

void	ft_free_darray(char **darr)
{
	int i;

	i = 0;
	while (darr && darr[i])
	{
		ft_free_str(darr[i]);
		i += 1;
	}
	if (darr)
	{
		free(darr);
		darr = NULL;
	}
}
