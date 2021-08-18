#include "libft.h"
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_tmp;

	p_tmp = (unsigned char*)b;
	while (len--)
	{
		*p_tmp = (unsigned char)c;
		p_tmp++;
	}
	return (b);
}
