#include "libft.h"
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, (int)('\0'), n);
}
