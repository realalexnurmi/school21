#include "libft.h"
// Memory allocation and initialization of fields [content]
// of a new node [new] of the list type
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	(*new).content = content;
	new->next = NULL;
	return (new);
}
