#include "libft.h"
size_t	ft_tab_size(char **tab)
{
	size_t	i;

	i = 0;
	while (*tab++)
		i++;
	return (i);
}
