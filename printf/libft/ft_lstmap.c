/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:51:13 by enena             #+#    #+#             */
/*   Updated: 2020/11/13 21:17:14 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_lst;
	t_list	*curr;

	begin_lst = NULL;
	if (lst && f && del)
	{
		if (!(begin_lst = ft_lstnew(f(lst->content))))
		{
			ft_lstdelone(begin_lst, del);
			return (NULL);
		}
		lst = lst->next;
		while (lst)
		{
			if (!(curr = ft_lstnew(f(lst->content))))
			{
				ft_lstclear(&begin_lst, del);
				return (begin_lst);
			}
			ft_lstadd_back(&begin_lst, curr);
			lst = lst->next;
		}
	}
	return (begin_lst);
}