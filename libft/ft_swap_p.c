#include "libft.h"
void	ft_swap_p(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}
