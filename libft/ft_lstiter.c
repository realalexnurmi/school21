#include "libft.h"
// Applying function [f] for every node of SLL list [lst]
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f)
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
}
