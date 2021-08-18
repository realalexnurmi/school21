#include "libft.h"
void	ft_swap_ch(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}
