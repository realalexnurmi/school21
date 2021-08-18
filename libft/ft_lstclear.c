#include "libft.h"
// Destructor of SLL list, applying for each node ft_delone
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (del)
		while (*lst)
		{
			next = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = next;
		}
}
