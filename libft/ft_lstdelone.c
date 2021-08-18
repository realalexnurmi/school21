#include "libft.h"
// Using the function of clearing fields [del]
// and freeing the memory storing the node
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
