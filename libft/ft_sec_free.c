#include "libft.h"
void	*ft_sec_free(void *p)
{
	if (p)
		free(p);
	return (NULL);
}
