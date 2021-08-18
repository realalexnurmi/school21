#include "libft.h"
// Function adding a new node [new] to the end of the SLL list [lst]
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}
