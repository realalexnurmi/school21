#include "libft.h"
// Function adding a new node [new] to the begin of the SLL list [lst]
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
