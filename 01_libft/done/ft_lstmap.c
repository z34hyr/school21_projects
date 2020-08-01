/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmalcom <qmalcom@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 16:59:13 by qmalcom           #+#    #+#             */
/*   Updated: 2020/05/08 19:07:47 by qmalcom          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *succ_case_list;
	t_list *list_beginning;
	t_list *new_elem;

	succ_case_list = NULL;
	list_beginning = NULL;
	while (lst && f && del)
	{
		if (f(lst->content))
		{
			if (!(new_elem = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&list_beginning, del);
				return (NULL);
			}
			if (succ_case_list)
				succ_case_list->next = new_elem;
			succ_case_list = new_elem;
			if (list_beginning == NULL)
				list_beginning = succ_case_list;
		}
		lst = lst->next;
	}
	return (list_beginning);
}
