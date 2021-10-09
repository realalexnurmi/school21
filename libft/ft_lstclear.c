/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enena <enena@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:21:29 by enena             #+#    #+#             */
/*   Updated: 2021/10/09 17:02:44 by enena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Destructor of SLL list, applying for each node ft_delone
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (del)
	{
		while (*lst)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next;
		}
	}
}
