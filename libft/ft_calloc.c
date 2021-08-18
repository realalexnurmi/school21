#include "libft.h"
void	*ft_calloc(size_t count, size_t size)
{
	void	*p_temp;

	p_temp = NULL;
	p_temp = malloc(count * size);
	if (p_temp)
		ft_bzero(p_temp, count * size);
	return (p_temp);
}
