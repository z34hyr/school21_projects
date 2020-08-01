/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:58:09 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/10 04:02:44 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *next_elem;
	t_list *curr_elem;

	if (!lst || !del)
		return ;
	curr_elem = *lst;
	while (curr_elem)
	{
		del(curr_elem->content);
		next_elem = curr_elem->next;
		free(curr_elem);
		curr_elem = next_elem;
	}
	*lst = NULL;
}
