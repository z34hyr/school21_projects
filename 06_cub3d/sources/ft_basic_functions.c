/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 02:25:16 by qmalcom           #+#    #+#             */
/*   Updated: 2020/10/15 01:37:01 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_argc(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		perror(ERR_WRONG_ARGS);
		exit(1);
	}
	if (argc == 3 && ft_strncmp(argv[2], SECOND_ARG, 6))
	{
		perror(ERR_WRONG_SEC_ARG);
		exit(1);
	}
	return (1);
}

void	ft_write_message(char *mess_name)
{
	write(1, mess_name, ft_strlen(mess_name));
	write(1, "\n", 1);
}

void	ft_skip_space(char *str, int *i)
{
	while (str && str[*i] && str[*i] == ' ')
		*i += 1;
}

void	ft_free_str(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	ft_strwrite(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
