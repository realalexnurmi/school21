#include "libft.h"
// Function returns the number of nodes [cnt] in the SLL list [lst] (aka size)
int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	if (lst)
	{
		cnt++;
		while (lst->next)
		{
			lst = lst->next;
			cnt++;
		}
	}
	return (cnt);
}
