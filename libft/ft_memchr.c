#include "libft.h"
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_srch;

	p_srch = (unsigned char*)s;
	while (n--)
	{
		if (*p_srch != (unsigned char)c)
			p_srch++;
		else
			return (p_srch);
	}
	return (NULL);
}
